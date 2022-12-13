#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <omp.h>
#include <iostream>
#include <string>
#include <vector>


// To compile c++ -O3 -Wall -shared -std=c++11 -fopenmp -fPIC $(python3 -m pybind11 --includes) WorseNumPy.cpp -o WorseNumPy$(python3-config --extension-suffix)

// intialized to -1 because number of processors is set to OpenMP default which is unknown
int P = -1;

void setProcessors(int num) {
    omp_set_num_threads(num);
    P = num;
}

int getProcessors() {
    return P;
}

// public methods that do not require the Matrix and Array class (for convenience)
template<typename T>
std::vector<std::vector<T>> addMatrixMatrix(std::vector<std::vector<T>> &m1, std::vector<std::vector<T>> &m2) {
    std::vector<T> subArray(m1[0].size(), 0);
    std::vector<std::vector<T>> m3(m1.size(), subArray);
    if (m1.size() != m2.size()) {
        throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
    }
    #pragma omp parallel for
        for (size_t x = 0; x < m1.size(); x++) {
            if (m1[x].size() != m2[x].size()) {
                throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }
            for (size_t y = 0; y < m1[x].size(); y++) {
                m3[x][y] = (m1[x][y] + m2[x][y]);
            }
        }
    return m3;
}

template<typename T>
std::vector<std::vector<T>> subtractMatrixMatrix(std::vector<std::vector<T>> &m1, std::vector<std::vector<T>> &m2) {
    std::vector<T> subArray(m1[0].size(), 0);
    std::vector<std::vector<T>> m3(m1.size(), subArray);
    if (m1.size() != m2.size()) {
        throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
    }
    #pragma omp parallel for
        for (size_t x = 0; x < m1.size(); x++) {
            if (m1[x].size() != m2[x].size()) {
                throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }
            for (size_t y = 0; y < m1[x].size(); y++) {
                m3[x][y] = (m1[x][y] - m2[x][y]);
            }
        }
    return m3;
}

template<typename T>
std::vector<std::vector<T>> multiplyMatrixMatrix(std::vector<std::vector<T>> &m1, std::vector<std::vector<T>> &m2) {
    std::vector<T> subArray(m2[0].size(), 0);
    std::vector<std::vector<T>> m3(m1.size(), subArray);

    #pragma omp parallel for
        for (size_t m1_row = 0; m1_row < m1.size(); m1_row++) {
            if (m1[m1_row].size() != m2.size()) {
                throw std::invalid_argument("Length of each row in matrix #1 must equal length of each column in matrix #2!");
            }
            for (size_t m2_col = 0; m2_col < m2[0].size(); m2_col++) {
                for (size_t idx = 0; idx < m1[m1_row].size(); idx++) {
                    if (m1.size() != m2[idx].size()) {
                        throw std::invalid_argument("Length of each column in matrix #1 must equal length of each row in matrix #2!");
                    }
                    m3[m1_row][m2_col] += m1[m1_row][idx] * m2[idx][m2_col];
                }
            }
        }
    return m3;
}

template<typename T>
std::vector<std::vector<T>> multiplyVectorMatrix(std::vector<T> &arr, std::vector<std::vector<T>> &mat) {
    std::vector<std::vector<T>> mat_b(3, {0});
    #pragma omp parallel for
        for (size_t i = 0; i < mat.size(); i++) {
            if (arr.size() != mat[i].size()) {
                throw std::invalid_argument("Length of all rows in the matrix must == legnth of the vector!");
            }
            for (size_t j = 0; j < mat[i].size(); j++) {
                mat_b[i][0] += (arr[j] * mat[i][j]);
            }
        }
    return mat_b;
}

template<typename T>
std::vector<T> addVectorVector(std::vector<T> &arr_x, std::vector<T> &arr_y) {
    if (arr_x.size() != arr_y.size()){
        throw std::invalid_argument("Length of vectors must the same!");
    }

    std::vector<T> arr_z(arr_x.size(), 0);
    #pragma omp parallel for
        for (size_t i = 0; i < arr_x.size(); i++) {
            arr_z[i] = (arr_x[i] + arr_y[i]);
        }
    return arr_z;
}

template<typename T>
std::vector<T> subtractVectorVector(std::vector<T> &arr_x, std::vector<T> &arr_y) {
    if (arr_x.size() != arr_y.size()){
        throw std::invalid_argument("Length of vectors must the same!");
    }

    std::vector<T> arr_z(arr_x.size(), 0);
    #pragma omp parallel for
        for (size_t i = 0; i < arr_x.size(); i++) {
            arr_z[i] = (arr_x[i] - arr_y[i]);
        }
    return arr_z;
}

template<typename T>
std::vector<T> multiplyVectorVector(std::vector<T> &arr_x, std::vector<T> &arr_y) {
    if (arr_x.size() != arr_y.size()){
        throw std::invalid_argument("Length of vectors must the same!");
    }

    std::vector<T> arr_z(arr_x.size(), 0);
    #pragma omp parallel for
        for (size_t i = 0; i < arr_x.size(); i++) {
            arr_z[i] = (arr_x[i] * arr_y[i]);
        }
    return arr_z;
}

template<typename T>
std::vector<std::vector<T>> scalarMatrixMultiply(T x, std::vector<std::vector<T>> mat) {
    #pragma omp parallel for
        for (size_t i = 0; i < mat.size(); i++) {
            for (size_t j = 0; j < mat[i].size(); j++) {
                mat[i][j] *= x;
            }
        }
    return mat;
}

template<typename T>
std::vector<std::vector<T>> scalarMatrixAdd(T x, std::vector<std::vector<T>> mat) {
    #pragma omp parallel for
        for (size_t i = 0; i < mat.size(); i++) {
            for (size_t j = 0; j < mat[i].size(); j++) {
                mat[i][j] += x;
            }
        }
    return mat;
}

template<typename T>
std::vector<std::vector<T>> scalarMatrixSubtract(T x, std::vector<std::vector<T>> mat) {
    #pragma omp parallel for
        for (size_t i = 0; i < mat.size(); i++) {
            for (size_t j = 0; j < mat[i].size(); j++) {
                mat[i][j] -= x;
            }
        }
    return mat;
}

template<typename T>

std::vector<T> scalarAddVector(T x, std::vector<T> arr) {
    #pragma omp parallel for
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] += x;
        }
    return arr;
}

template<typename T>
std::vector<T> scalarSubtractVector(T x, std::vector<T> arr) {
    #pragma omp parallel for
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] -= x;
        }
    return arr;
}

template<typename T>
std::vector<T> scalarMultiplyVector(T x, std::vector<T> arr) {
    #pragma omp parallel for
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] *= x;
        }
    return arr;
}


template <typename T>
class Matrix {
    public:
        // constructor method to create n x m matrix
        Matrix(int rowSize, int colSize, T value = 0) {
            if (rowSize < 1 or colSize < 1) {
                throw std::invalid_argument("Row size and column size must be greater than 0!");
            }
            rows = rowSize;
            cols = colSize;
            std::vector<T> subArray(cols, 0);
            std::vector<std::vector<T>> tmp_mat(rows, subArray);
            #pragma omp parallel for
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        tmp_mat[i][j] = value;
                    }
                }
            mat = tmp_mat;
        }
        // constructor method to create a matrix when a std::vector<std::vector<T>> is passed in 
        Matrix(std::vector<std::vector<T>> mat_b) {
            rows = mat_b.size();
            if (mat_b.size() > 0) {
                cols = mat_b[0].size();
            }
            else {
                cols = 0;
            }
            #pragma omp parallel for
                for (std::vector<T> row : mat_b) {
                    int rowSize = row.size();
                    if (rowSize != cols) {
                        throw std::invalid_argument("Length of each row must match!");
                    }
                }
            
            mat = mat_b;
        }

        // get element in matrix
        T getItem(int i, int j) {
            if (i < 0 or i >= rows or j < 0 or j >= cols) {
                throw std::invalid_argument("getItem: Invalid index!");
            }
            return mat[i][j];
        }
        // get row in matrix
        std::vector<T> getRow(int i) {
            if (i < 0 or i >= cols) {
                throw std::invalid_argument("getRow: Invalid index!");
            }
            return mat[i];
        }
        // set element in matrix
        void setItem(int i, int j, T x) {
            if (i < 0 or i >= rows or j < 0 or j >= cols) {
                throw std::invalid_argument("setItem: Invalid index!");
            }
            mat[i][j] = x;
        }
        // set entire sub array in the matrix
        void setRow(int i, std::vector<T> x) {
            if (i < 0 or i >= cols) {
                throw std::invalid_argument("setRow: Invalid index!");
            }
            if (x.size() != mat[i].size()) {
                throw std::invalid_argument("Array size does not match matrix dimensions!");
            }
            size_t j = i;
            if (i < -1 or j > mat.size() - 1) {
                throw std::invalid_argument("Index out of bounds!");
            }
            mat[i] = x;
        }
        
        // Matrix scalar opertations
        Matrix scalarAdd(T const &x) const {
            Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
            #pragma omp parallel for
                for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
                    for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                        tmp_mat.mat[i][j] = mat[i][j] + x;
                    }
                }
            return tmp_mat;
        }

        Matrix scalarSubtract(T const &x) const {
            Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
            #pragma omp parallel for
                for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
                    for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                        tmp_mat.mat[i][j] = mat[i][j] - x;
                    }
                }
            return tmp_mat;
        }

        Matrix scalarMultiply(T const &x) const {
            Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
            #pragma omp parallel for
                for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
                    for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                        tmp_mat.mat[i][j] = mat[i][j] * x;
                    }
                }
            return tmp_mat;
        }

        // Matrix Matrix operations
        Matrix addMatrix(Matrix const &m1) const{
            if (rows != m1.rows or cols != m1.cols) {
                throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }

            Matrix m3 = Matrix(mat.size(), mat[0].size(), 0);
            #pragma omp parallel for
                for (size_t x = 0; x < m1.mat.size(); x++) {
                    for (size_t y = 0; y < mat[x].size(); y++) {
                        m3.mat[x][y] = mat[x][y] + m1.mat[x][y];
                    }
                }
            return m3;
        }

        Matrix subtractMatrix(Matrix const &m1) const{
            if (rows != m1.rows or cols != m1.cols) {
                throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }

            Matrix m3 = Matrix(mat.size(), mat[0].size(), 0);
            #pragma omp parallel for
                for (size_t x = 0; x < m1.mat.size(); x++) {
                    for (size_t y = 0; y < mat[x].size(); y++) {
                        m3.mat[x][y] = mat[x][y] - m1.mat[x][y];
                    }
                }
            return m3;
        }

        Matrix multiplyMatrix(Matrix const &m1) const {
            if (cols != m1.rows) {
                throw std::invalid_argument("Number of columns in matrix #1 must equal length of the number of rows in matrix #2!");
            }
            Matrix tmp_mat = Matrix(mat.size(), m1.mat[0].size(), 0);
            #pragma omp parallel for
                for (size_t mat_row = 0; mat_row < mat.size(); mat_row++) {
                    if (mat[mat_row].size() != m1.mat.size()) {
                    }
                    for (size_t m1_col = 0; m1_col < m1.mat[0].size(); m1_col++) {
                        for (size_t idx = 0; idx < mat[mat_row].size(); idx++) {
                            tmp_mat.mat[mat_row][m1_col] += mat[mat_row][idx] * m1.mat[idx][m1_col];
                        }
                    }
                }
            return tmp_mat;
        }

        // overload opertations
        Matrix operator+(T a) const {
            return scalarAdd(a);
        }

        Matrix operator+=(T a) {
            #pragma omp parallel for
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        mat[i][j] = mat[i][j] + a;
                    }
                }
            return *this;
        }

        Matrix operator-(T a) const {
            return scalarSubtract(a);
        }

        Matrix operator-=(T a) {
            #pragma omp parallel for
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        mat[i][j] = mat[i][j] - a;
                    }
                }
            return *this;
        }

        Matrix operator*(T a) const {
            return scalarMultiply(a);
        }
        
        Matrix operator*=(T a) {
            #pragma omp parallel for
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        mat[i][j] = mat[i][j] * a;
                    }
                }
            return *this;
        }

        Matrix operator+(Matrix const &mat_b) const {
            return addMatrix(mat_b);
        }

        Matrix operator+=(Matrix const &mat_b) {
            if (rows != mat_b.rows) {
                    throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }
            #pragma omp parallel for
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        mat[i][j] = mat[i][j] + mat_b.mat[i][j];
                    }
                }
            return *this;
        }

        Matrix operator-(Matrix const &mat_b) const {
            return subtractMatrix(mat_b);
        }

        Matrix operator-=(Matrix const &mat_b) {
            if (rows != mat_b.rows) {
                    throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }
            #pragma omp parallel for
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        mat[i][j] = mat[i][j] - mat_b.mat[i][j];
                    }
                }
            return *this;
        }

        Matrix operator*(Matrix const &mat_b) const {
            return multiplyMatrix(mat_b);
        }

        Matrix operator*=(Matrix const &mat_b) const {
            return multiplyMatrix(mat_b);
        }

        std::vector<T> L1Norm() {
            std::vector<T> normVec(cols, 0);
            #pragma omp parallel for
                for (int col = 0; col < cols; col++) {
                    for (int row = 0; row < rows; row++) {
                        normVec[col] += abs(mat[row][col]);
                    }
                }
            return normVec;
        }

        std::vector<float> L2Norm() {
            std::vector<float> normVec(cols, 0);
            #pragma omp parallel for
                for (int col = 0; col < cols; col++) {
                    for (int row = 0; row < rows; row++) {
                        normVec[col] += pow(mat[row][col], 2);
                    }
                    normVec[col] = sqrt(normVec[col]);
                }
            return normVec;
        }

        std::string __repr__() {
            std::string msg = "[";
            for (size_t i = 0; i < mat.size() - 1; i++) {
                msg += rowToString(mat[i]) + ", ";
            }

            msg += rowToString(mat[mat.size() - 1]) + "]";
            return msg;
        }

    private:
        std::vector<std::vector<T>> mat;
        int rows;
        int cols;
        std::string rowToString(std::vector<T> &row) {
            std::string msg = "[";

            if (row.size() == 0) {
                msg = "[]";
                return msg;
            }
            for (size_t j = 0; j < row.size() - 1; j++) {
                msg += std::to_string(row[j]) + ", ";
            }
            msg += std::to_string(row[row.size() - 1]) + "]";

            return msg;
        }
      
};

template <typename T>
class Array {
    public:
        // constructors
        Array(int size, T value = 0) {
            std::vector<T> tmp(size, value);
            arr = tmp;
        }
        Array(std::vector<T> arr_b) {
            arr = arr_b;
        }

               
        T getItem(int i) {
            return arr[i];
        }
        void setItem(int i, T x) {
            arr[i] = x;
        }

        // Array scalar opertaions 
        Array scalarAdd(T const &x) const {
            Array tmp = arr;
            #pragma omp parallel for
                for (size_t i = 0; i < tmp.arr.size(); i++) {
                    tmp.arr[i] += x;
                }
            return tmp;
        }

        Array scalarSubtract(T const &x) const {
            Array tmp = arr;
            #pragma omp parallel for
                for (size_t i = 0; i < tmp.arr.size(); i++) {
                    tmp.arr[i] -= x;
                }
            return tmp;
        }

        Array scalarMultiply(T const &x) const {
            Array tmp = arr;
            #pragma omp parallel for
                for (size_t i = 0; i < tmp.arr.size(); i++) {
                    tmp.arr[i] *= x;
                }
            return tmp;
        }

        // Array Array operations
        Array addArray(Array const &arr_y) const {
            Array tmp = arr;
            if (tmp.arr.size() != arr_y.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }
            #pragma omp parallel for
                for (size_t i = 0; i < tmp.arr.size(); i++) {
                    tmp.arr[i] += arr_y.arr[i];
                }
            return tmp;
        }

        Array subtractArray(Array const &arr_y) const {
            Array tmp = arr;
            if (tmp.arr.size() != arr_y.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }
            #pragma omp parallel for
                for (size_t i = 0; i < tmp.arr.size(); i++) {
                    tmp.arr[i] -= arr_y.arr[i];
                }
            return tmp;
        }

        Array multiplyArray(Array const &arr_y) const {
            Array tmp = arr;
            if (tmp.arr.size() != arr_y.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }
            #pragma omp parallel for
                for (size_t i = 0; i < tmp.arr.size(); i++) {
                    tmp.arr[i] *= arr_y.arr[i];
                }
            return tmp;
        }

        // overload opertators
        Array operator+(T x) const {
            return scalarAdd(x);
        }

        Array operator+=(T x) {
            #pragma omp parallel for
                for (size_t i = 0; i < arr.size(); i++) {
                    arr[i] += x;
                }

            return *this;
        }

        Array operator-(T x) const {
            return scalarSubtract(x);
        }

        Array operator-=(T x) {
            #pragma omp parallel for
                for (size_t i = 0; i < arr.size(); i++) {
                    arr[i] -= x;
                }
            
            return *this;
        }

        Array operator*(T x) const {
            return scalarMultiply(x);
        }

        Array operator*=(T x) {
            #pragma omp parallel for
                for (size_t i = 0; i < arr.size(); i++) {
                    arr[i] *= x;
                }
            
            return *this;
        }

        Array operator+(Array const &vec) const {
            return addArray(vec);
        }

        Array operator+=(Array const &vec) {
            if (arr.size() != vec.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }
            #pragma omp parallel for
                for (size_t i = 0; i < arr.size(); i++) {
                    arr[i] += vec.arr[i];
                }
            return *this;
        }

        Array operator-(Array const &vec) const {
            return subtractArray(vec);
        }

        Array operator-=(Array const &vec) {
            if (arr.size() != vec.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }
            #pragma omp parallel for
                for (size_t i = 0; i < arr.size(); i++) {
                    arr[i] -= vec.arr[i];
                }
            return *this;
        }

        Array operator*(Array const &vec) const {
            return multiplyArray(vec);
        }

        Array operator*=(Array const &vec) {
            if (arr.size() != vec.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }
            #pragma omp parallel for
                for (size_t i = 0; i < arr.size(); i++) {
                    arr[i] *= vec.arr[i];
                }
            return *this;
        }

        T L1Norm() {
            T acc = 0;
            #pragma omp parallel for
                for (T element : arr) {
                    acc += abs(element);
                }
            return acc;
        }

        float L2Norm() {
            T acc = 0;
            #pragma omp parallel for
                for (T element : arr) {
                    acc += pow(element, 2);
                }
            float ans = sqrt(acc);
            return ans;
        }

        std::string __repr__() {
            if (arr.size() == 0) {
                return "[]";
            }

            std::string msg = "[";
            for (size_t i = 0; i < arr.size()-1; i++) {
                msg += std::to_string(arr[i]) + ", ";
            }
            msg += std::to_string(arr[arr.size()-1]) + "]";

            return msg;
        }

    private:
        std::vector<T> arr;
      
};


PYBIND11_MODULE(WorseNumPy, m) {
    m.doc() = "Our attempt to create a parallelized matrix library similar to NumPy";

    pybind11::class_<Matrix<int>>(m, "MatrixInt")
        .def(pybind11::init<std::vector<std::vector<int>>>())
        .def(pybind11::init<int, int, int>())
        .def(pybind11::init<int, int>())
        .def("getItem", &Matrix<int>::getItem)
        .def("getRow", &Matrix<int>::getRow)
        .def("setItem", &Matrix<int>::setItem)
        .def("setRow", &Matrix<int>::setRow)
        .def("__repr__", &Matrix<int>::__repr__)
        .def("addMatrix", &Matrix<int>::addMatrix)
        .def("subtractMatrix", &Matrix<int>::subtractMatrix)
        .def("multiplyMatrix", &Matrix<int>::multiplyMatrix)
        .def("scalarMultiply", &Matrix<int>::scalarMultiply)
        .def("scalarAdd", &Matrix<int>::scalarAdd)
        .def("scalarSubtract", &Matrix<int>::scalarSubtract)
        .def(pybind11::self + int())
        .def(pybind11::self += int())
        .def(pybind11::self - int())
        .def(pybind11::self -= int())
        .def(pybind11::self * int())
        .def(pybind11::self *= int())
        .def(pybind11::self + pybind11::self)
        .def(pybind11::self += pybind11::self)
        .def(pybind11::self - pybind11::self)
        .def(pybind11::self -= pybind11::self)
        .def(pybind11::self * pybind11::self)
        .def(pybind11::self *= pybind11::self)
        .def("L1Norm", &Matrix<int>::L1Norm)
        .def("L2Norm", &Matrix<int>::L2Norm);

    pybind11::class_<Matrix<float>>(m, "MatrixFloat")
        .def(pybind11::init<std::vector<std::vector<float>>>())
        .def(pybind11::init<float, float, float>())
        .def(pybind11::init<float, float>())
        .def("getItem", &Matrix<float>::getItem)
        .def("getRow", &Matrix<float>::getRow)
        .def("setItem", &Matrix<float>::setItem)
        .def("setRow", &Matrix<float>::setRow)
        .def("__repr__", &Matrix<float>::__repr__)
        .def("addMatrix", &Matrix<float>::addMatrix)
        .def("subtractMatrix", &Matrix<float>::subtractMatrix)
        .def("multiplyMatrix", &Matrix<float>::multiplyMatrix)
        .def("scalarMultiply", &Matrix<float>::scalarMultiply)
        .def("scalarAdd", &Matrix<float>::scalarAdd)
        .def("scalarSubtract", &Matrix<float>::scalarSubtract)
        .def(pybind11::self + float())
        .def(pybind11::self += float())
        .def(pybind11::self - float())
        .def(pybind11::self -= float())
        .def(pybind11::self * float())
        .def(pybind11::self *= float())
        .def(pybind11::self + pybind11::self)
        .def(pybind11::self += pybind11::self)
        .def(pybind11::self - pybind11::self)
        .def(pybind11::self -= pybind11::self)
        .def(pybind11::self * pybind11::self)
        .def(pybind11::self *= pybind11::self)
        .def("L1Norm", &Matrix<float>::L1Norm)
        .def("L2Norm", &Matrix<float>::L2Norm);

    pybind11::class_<Matrix<double>>(m, "MatrixDouble")
        .def(pybind11::init<std::vector<std::vector<double>>>())
        .def(pybind11::init<double, double, double>())
        .def(pybind11::init<double, double>())
        .def("getItem", &Matrix<double>::getItem)
        .def("getRow", &Matrix<double>::getRow)
        .def("setItem", &Matrix<double>::setItem)
        .def("setRow", &Matrix<double>::setRow)
        .def("__repr__", &Matrix<double>::__repr__)
        .def("addMatrix", &Matrix<double>::addMatrix)
        .def("subtractMatrix", &Matrix<double>::subtractMatrix)
        .def("multiplyMatrix", &Matrix<double>::multiplyMatrix)
        .def("scalarMultiply", &Matrix<double>::scalarMultiply)
        .def("scalarAdd", &Matrix<double>::scalarAdd)
        .def("scalarSubtract", &Matrix<double>::scalarSubtract)
        .def(pybind11::self + double())
        .def(pybind11::self += double())
        .def(pybind11::self - double())
        .def(pybind11::self -= double())
        .def(pybind11::self * double())
        .def(pybind11::self *= double())
        .def(pybind11::self + pybind11::self)
        .def(pybind11::self += pybind11::self)
        .def(pybind11::self - pybind11::self)
        .def(pybind11::self -= pybind11::self)
        .def(pybind11::self * pybind11::self)
        .def(pybind11::self *= pybind11::self)
        .def("L1Norm", &Matrix<double>::L1Norm)
        .def("L2Norm", &Matrix<double>::L2Norm);;

    pybind11::class_<Array<int>>(m, "ArrayInt")
        .def(pybind11::init<std::vector<int>>())
        .def(pybind11::init<int, int>())
        .def(pybind11::init<int>())
        .def("scalarAdd", &Array<int>::scalarAdd)
        .def("scalarSubtract", &Array<int>::scalarSubtract)
        .def("scalarMultiply", &Array<int>::scalarMultiply)
        .def("addArray", &Array<int>::addArray)
        .def("subtractArray", &Array<int>::subtractArray)
        .def("multiplyArray", &Array<int>::multiplyArray)
        .def("getItem", &Array<int>::getItem)
        .def("setItem", &Array<int>::setItem)
        .def(pybind11::self + int())
        .def(pybind11::self += int())
        .def(pybind11::self - int())
        .def(pybind11::self -= int())
        .def(pybind11::self * int())
        .def(pybind11::self *= int())
        .def(pybind11::self + pybind11::self)
        .def(pybind11::self += pybind11::self)
        .def(pybind11::self - pybind11::self)
        .def(pybind11::self -= pybind11::self)
        .def(pybind11::self * pybind11::self)
        .def(pybind11::self *= pybind11::self)
        .def("__repr__", &Array<int>::__repr__)
        .def("L1Norm", &Array<int>::L1Norm)
        .def("L2Norm", &Array<int>::L2Norm);

    pybind11::class_<Array<float>>(m, "ArrayFloat")
        .def(pybind11::init<std::vector<float>>())
        .def(pybind11::init<float, float>())
        .def(pybind11::init<float>())
        .def("scalarAdd", &Array<float>::scalarAdd)
        .def("scalarSubtract", &Array<float>::scalarSubtract)
        .def("scalarMultiply", &Array<float>::scalarMultiply)
        .def("addArray", &Array<float>::addArray)
        .def("subtractArray", &Array<float>::subtractArray)
        .def("multiplyArray", &Array<float>::multiplyArray)
        .def("getItem", &Array<float>::getItem)
        .def("setItem", &Array<float>::setItem)
        .def(pybind11::self + float())
        .def(pybind11::self += float())
        .def(pybind11::self - float())
        .def(pybind11::self -= float())
        .def(pybind11::self * float())
        .def(pybind11::self *= float())
        .def(pybind11::self + pybind11::self)
        .def(pybind11::self += pybind11::self)
        .def(pybind11::self - pybind11::self)
        .def(pybind11::self -= pybind11::self)
        .def(pybind11::self * pybind11::self)
        .def(pybind11::self *= pybind11::self)
        .def("__repr__", &Array<float>::__repr__)
        .def("L1Norm", &Array<float>::L1Norm)
        .def("L2Norm", &Array<float>::L2Norm);

    pybind11::class_<Array<double>>(m, "ArrayDouble")
        .def(pybind11::init<std::vector<double>>())
        .def(pybind11::init<double, double>())
        .def(pybind11::init<double>())
        .def("scalarAdd", &Array<double>::scalarAdd)
        .def("scalarSubtract", &Array<double>::scalarSubtract)
        .def("scalarMultiply", &Array<double>::scalarMultiply)
        .def("addArray", &Array<double>::addArray)
        .def("subtractArray", &Array<double>::subtractArray)
        .def("multiplyArray", &Array<double>::multiplyArray)
        .def("getItem", &Array<double>::getItem)
        .def("setItem", &Array<double>::setItem)
        .def(pybind11::self + double())
        .def(pybind11::self += double())
        .def(pybind11::self - double())
        .def(pybind11::self -= double())
        .def(pybind11::self * double())
        .def(pybind11::self *= double())
        .def(pybind11::self + pybind11::self)
        .def(pybind11::self += pybind11::self)
        .def(pybind11::self - pybind11::self)
        .def(pybind11::self -= pybind11::self)
        .def(pybind11::self * pybind11::self)
        .def(pybind11::self *= pybind11::self)
        .def("__repr__", &Array<double>::__repr__)
        .def("L1Norm", &Array<double>::L1Norm)
        .def("L2Norm", &Array<double>::L2Norm);


    m.def("setProcessors", &setProcessors, "A function that sets the number of processors for the library");
    m.def("getProcessors", &getProcessors, "A function that returns the number of processors set for the library");
    m.def("multiplyVectorMatrix", &multiplyVectorMatrix<int>, "A function that does vector-matrix multiplication");
    m.def("addVectorVector", &addVectorVector<int>, "A function that adds together values at equivalent indices between two vectors");
    m.def("subtractVectorVector", &subtractVectorVector<int>, "A function that subtracts two values at equivalent indices between two vectors");
    m.def("multiplyVectorVector", &multiplyVectorVector<int>, "A function that multiplies two values at equivalent indices between two vectors");
    m.def("scalarMatrixMultiply", &scalarMatrixMultiply<int>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixAdd", &scalarMatrixAdd<int>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixSubtract", &scalarMatrixSubtract<int>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarAddVector", &scalarAddVector<int>, "A function that takes an integer, and performs scalar addition on a vector");
    m.def("scalarSubtractVector", &scalarSubtractVector<int>, "A function that takes an integer, and performs scalar subtraction on a vector");
    m.def("scalarMultiplyVector", &scalarMultiplyVector<int>, "A function that takes an integer, and performs scalar multiplication on a vector");
    m.def("multiplyMatrixMatrix", &multiplyMatrixMatrix<int>, "A function that peforms matrix multiplication on two matrices of integers");
    m.def("addMatrixMatrix", &addMatrixMatrix<int>, "A function that peforms matrix addition on two matrices of integers");
    m.def("subtractMatrixMatrix", &subtractMatrixMatrix<int>, "A function that peforms matrix subtraction on two matrices of integers");
    
    m.def("multiplyVectorMatrix", &multiplyVectorMatrix<float>, "A function that does vector-matrix multiplication");
    m.def("addVectorVector", &addVectorVector<float>, "A function that adds together values at equivalent indices between two vectors");
    m.def("subtractVectorVector", &subtractVectorVector<float>, "A function that subtracts two values at equivalent indices between two vectors");
    m.def("multiplyVectorVector", &multiplyVectorVector<float>, "A function that multiplies two values at equivalent indices between two vectors");
    m.def("scalarMatrixMultiply", &scalarMatrixMultiply<float>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixAdd", &scalarMatrixAdd<float>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixSubtract", &scalarMatrixSubtract<float>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarAddVector", &scalarAddVector<float>, "A function that takes an integer, and performs scalar addition on a vector");
    m.def("scalarSubtractVector", &scalarSubtractVector<float>, "A function that takes an integer, and performs scalar subtraction on a vector");
    m.def("scalarMultiplyVector", &scalarMultiplyVector<float>, "A function that takes an integer, and performs scalar multiplication on a vector");
    m.def("multiplyMatrixMatrix", &multiplyMatrixMatrix<float>, "A function that peforms matrix multiplication on two matrices of integers");
    m.def("addMatrixMatrix", &addMatrixMatrix<float>, "A function that peforms matrix addition on two matrices of integers");
    m.def("subtractMatrixMatrix", &subtractMatrixMatrix<float>, "A function that peforms matrix subtraction on two matrices of integers");

    m.def("multiplyVectorMatrix", &multiplyVectorMatrix<double>, "A function that does vector-matrix multiplication");
    m.def("addVectorVector", &addVectorVector<double>, "A function that adds together values at equivalent indices between two vectors");
    m.def("subtractVectorVector", &subtractVectorVector<double>, "A function that subtracts two values at equivalent indices between two vectors");
    m.def("multiplyVectorVector", &multiplyVectorVector<double>, "A function that multiplies two values at equivalent indices between two vectors");
    m.def("scalarMatrixMultiply", &scalarMatrixMultiply<double>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixAdd", &scalarMatrixAdd<double>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixSubtract", &scalarMatrixSubtract<double>, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarAddVector", &scalarAddVector<double>, "A function that takes an integer, and performs scalar addition on a vector");
    m.def("scalarSubtractVector", &scalarSubtractVector<double>, "A function that takes an integer, and performs scalar subtraction on a vector");
    m.def("scalarMultiplyVector", &scalarMultiplyVector<double>, "A function that takes an integer, and performs scalar multiplication on a vector");
    m.def("multiplyMatrixMatrix", &multiplyMatrixMatrix<double>, "A function that peforms matrix multiplication on two matrices of integers");
    m.def("addMatrixMatrix", &addMatrixMatrix<double>, "A function that peforms matrix addition on two matrices of integers");
    m.def("subtractMatrixMatrix", &subtractMatrixMatrix<double>, "A function that peforms matrix subtraction on two matrices of integers");
}
