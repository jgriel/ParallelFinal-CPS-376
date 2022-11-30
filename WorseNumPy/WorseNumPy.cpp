#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <string>
#include <vector>


// To compile c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) WorseNumPy.cpp -o WorseNumPy$(python3-config --extension-suffix)


int P = 1;

void setProcessors(int num) {
    P = num;
}

std::string getProcessors() {
    return std::to_string(P);
}

int addInt(int i, int j) {
    return i + j;
}

int subtractInt(int i, int j) {
    return i - j;
}

int multiplyInt(int i, int j) {
    return i * j;
}

std::vector<std::vector<int>> addMatrixMatrix(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2) {
    std::vector<std::vector<int>> m3 = {};
    if (m1.size() != m2.size()) {
        throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
    }
    for (size_t x = 0; x < m1.size(); x++) {
        if (m1[x].size() != m2[x].size()) {
            throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
        }
        std::vector<int> tmp = {};
        for (size_t y = 0; y < m1[x].size(); y++) {
            tmp.push_back(m1[x][y] + m2[x][y]);
        }
        m3.push_back(tmp);
    }
    return m3;
}

std::vector<std::vector<int>> subtractMatrixMatrix(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2) {
    std::vector<std::vector<int>> m3 = {};
    if (m1.size() != m2.size()) {
        throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
    }
    for (size_t x = 0; x < m1.size(); x++) {
        if (m1[x].size() != m2[x].size()) {
            throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
        }
        std::vector<int> tmp = {};
        for (size_t y = 0; y < m1[x].size(); y++) {
            tmp.push_back(m1[x][y] - m2[x][y]);
        }
        m3.push_back(tmp);
    }
    return m3;
}

std::vector<std::vector<int>> multiplyMatrixMatrix(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2) {
    std::vector<std::vector<int>> m3 = {};
    for (size_t m1_row = 0; m1_row < m1.size(); m1_row++) {
        if (m1[m1_row].size() != m2.size()) {
            throw std::invalid_argument("Length of each row in matrix #1 must equal length of each column in matrix #2!");
        }
        std::vector<int> tmp = {};
        for (size_t m2_col = 0; m2_col < m2[0].size(); m2_col++) {
            int acc = 0;
            for (size_t idx = 0; idx < m1[m1_row].size(); idx++) {
                if (m1.size() != m2[idx].size()) {
                    throw std::invalid_argument("Length of each column in matrix #1 must equal length of each row in matrix #2!");
                }
                acc += m1[m1_row][idx] * m2[idx][m2_col];
            }
            tmp.push_back(acc);
        }
        m3.push_back(tmp);
    }
    return m3;
}

std::vector<std::vector<int>> multiplyVectorMatrix(std::vector<int> arr, std::vector<std::vector<int>> mat) {
    std::vector<std::vector<int>> mat_b = {};
    for (size_t i = 0; i < mat.size(); i++) {
        if (arr.size() != mat[i].size()) {
            throw std::invalid_argument("Length of all rows in the matrix must == legnth of the vector!");
        }

        mat_b.push_back({});
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat_b[i].push_back(arr[j] * mat[i][j]);
        }
    }
    return mat_b;
}

std::vector<int> addVectorVector(std::vector<int> arr_x, std::vector<int> arr_y) {
    if (arr_x.size() != arr_y.size()){
        throw std::invalid_argument("Length of vectors must the same!");
    }

    std::vector<int> arr_z = {};
    for (size_t i = 0; i < arr_x.size(); i++) {
        arr_z.push_back(arr_x[i] + arr_y[i]);
    }
    return arr_z;
}

std::vector<int> subtractVectorVector(std::vector<int> arr_x, std::vector<int> arr_y) {
    if (arr_x.size() != arr_y.size()){
        throw std::invalid_argument("Length of vectors must the same!");
    }

    std::vector<int> arr_z = {};
    for (size_t i = 0; i < arr_x.size(); i++) {
        arr_z.push_back(arr_x[i] - arr_y[i]);
    }
    return arr_z;
}

std::vector<int> multiplyVectorVector(std::vector<int> arr_x, std::vector<int> arr_y) {
    if (arr_x.size() != arr_y.size()){
        throw std::invalid_argument("Length of vectors must the same!");
    }

    std::vector<int> arr_z = {};
    for (size_t i = 0; i < arr_x.size(); i++) {
        arr_z.push_back(arr_x[i] * arr_y[i]);
    }
    return arr_z;
}

std::vector<std::vector<int>> scalarMatrixMultiply(int x, std::vector<std::vector<int>> mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j] *= x;
        }
    }
    return mat;
}

std::vector<std::vector<int>> scalarMatrixAdd(int x, std::vector<std::vector<int>> mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j] += x;
        }
    }
    return mat;
}

std::vector<std::vector<int>> scalarMatrixSubtract(int x, std::vector<std::vector<int>> mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j] -= x;
        }
    }
    return mat;
}

std::vector<int> scalarAddVector(int x, std::vector<int> arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] += x;
    }
    return arr;
}

std::vector<int> scalarSubtractVector(int x, std::vector<int> arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] -= x;
    }
    return arr;
}

std::vector<int> scalarMultiplyVector(int x, std::vector<int> arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] *= x;
    }
    return arr;
}


template <typename T>
class Matrix {
    public:
        // NOTE: crashes when n = 0
        Matrix(int rows, int cols, T value = 0) {
            std::vector<std::vector<T>> tmp;
            std::vector<T> subVec = {};
            for (int i = 0; i < rows; i++) {
                tmp.push_back(subVec);
                for (int j = 0; j < cols; j++) {
                    tmp[i].push_back(value);
                }
            }
            mat = tmp;
        }

        Matrix(std::vector<std::vector<T>> mat_b) {
            mat = mat_b;
        }

        std::string toString() {
            std::string msg = "[";
            for (size_t i = 0; i < mat.size() - 1; i++) {
                msg += rowToString(mat[i]) + ", ";
            }

            msg += rowToString(mat[mat.size() - 1]) + "]";
            return msg;
        }

        Matrix addMatrix(Matrix const &m1) const{
            Matrix m3 = Matrix(mat.size(), mat[0].size(), 0);
            if (mat.size() != m1.mat.size()) {
                throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }
            for (size_t x = 0; x < m1.mat.size(); x++) {
                if (mat[x].size() != m1.mat[x].size()) {
                    throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
                }
                for (size_t y = 0; y < mat[x].size(); y++) {
                    m3.mat[x][y] = mat[x][y] + m1.mat[x][y];
                }
            }
            return m3;
        }

        Matrix subtractMatrix(Matrix const &m1) const{
            Matrix m3 = Matrix(mat.size(), mat[0].size(), 0);
            if (mat.size() != m1.mat.size()) {
                throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
            }
            for (size_t x = 0; x < m1.mat.size(); x++) {
                if (mat[x].size() != m1.mat[x].size()) {
                    throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
                }
                for (size_t y = 0; y < mat[x].size(); y++) {
                    m3.mat[x][y] = mat[x][y] - m1.mat[x][y];
                }
            }
            return m3;
        }

        Matrix multiplyMatrix(Matrix const &m1) const {
            Matrix tmp_mat = Matrix(mat.size(), m1.mat[0].size(), 0);
            for (size_t mat_row = 0; mat_row < mat.size(); mat_row++) {
                if (mat[mat_row].size() != m1.mat.size()) {
                    throw std::invalid_argument("Columns in each row of matrix #1 must equal length number of rows in matrix #2!");
                }
                for (size_t m1_col = 0; m1_col < m1.mat[0].size(); m1_col++) {
                    int acc = 0;
                    for (size_t idx = 0; idx < mat[mat_row].size(); idx++) {
                        if (mat.size() != m1.mat[idx].size()) {
                            throw std::invalid_argument("Length of each column in matrix #1 must equal length of each row in matrix #2!");
                        }
                        acc += mat[mat_row][idx] * m1.mat[idx][m1_col];
                    }
                    tmp_mat.mat[mat_row][m1_col] = acc;
                }
            }
            return tmp_mat;
        }

        Matrix scalarMultiply(T const &x) const {
            Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
            for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
                for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                    tmp_mat.mat[i][j] = mat[i][j] * x;
                }
            }
            return tmp_mat;
        }

        Matrix scalarAdd(T const &x) const {
            Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
            for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
                for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                    tmp_mat.mat[i][j] = mat[i][j] + x;
                }
            }
            return tmp_mat;
        }

        Matrix scalarSubtract(T const &x) const {
            Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
            for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
                for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                    tmp_mat.mat[i][j] = mat[i][j] - x;
                }
            }
            return tmp_mat;
        }

        // Matrix multiplyVectorMatrix(Array arr) {
            // std::vector<std::vector<int>> mat_b = {};
            // for (size_t i = 0; i < mat.size(); i++) {
            //     if (arr.size() != mat[i].size()) {
            //         throw std::invalid_argument("Length of all rows in the matrix must == legnth of the vector!");
            //     }

            //     mat_b.push_back({});
            //     for (size_t j = 0; j < mat[i].size(); j++) {
            //         mat_b[i].push_back(arr[j] * mat[i][j]);
            //     }
            // }
        //     Matrix tmp = Matrix(0,0,0);
        //     return tmp;
        // }

        //__getitem__
        T getItem(int i, int j) {
            return mat[i][j];
        }
        std::vector<T> getArray(int i) {
            return mat[i];
        }
        
        //set single element
        void setItem(int i, int j, T x) {
            mat[i][j] = x;
        }
        //set entire row
        void setArray(int i, std::vector<T> x) {
            if (x.size() != mat[i].size()) {
                throw std::invalid_argument("Array size does not match matrix dimensions!");
            }
            size_t j = i;
            if (i < -1 or j > mat.size() - 1) {
                throw std::invalid_argument("Index out of bounds!");
            }
            mat[i] = x;
        }
        

        // Matrix scalar operations
        Matrix operator+(T a) const {
            return scalarAdd(a);
        }
        Matrix operator+=(T a) const {
            return scalarAdd(a);
        }

        Matrix operator-(T a) const {
            return scalarSubtract(a);
        }
        Matrix operator-=(T a) const {
            return scalarSubtract(a);
        }

        Matrix operator*(T a) const {
            return scalarMultiply(a);
        }
        Matrix operator*=(T a) const {
            return scalarMultiply(a);
        }

        // Matrix Matrix operations
        Matrix operator+(Matrix const &mat_b) const {
            return addMatrix(mat_b);
        }
        Matrix operator+=(Matrix const &mat_b) const {
            return addMatrix(mat_b);
        }

        Matrix operator-(Matrix const &mat_b) const {
            return subtractMatrix(mat_b);
        }
        Matrix operator-=(Matrix const &mat_b) const {
            return subtractMatrix(mat_b);
        }

        Matrix operator*(Matrix const &mat_b) const {
            return multiplyMatrix(mat_b);
        }
        Matrix operator*=(Matrix const &mat_b) const {
            return multiplyMatrix(mat_b);
        }

        // Matrix Vector Opertations
    private:
        std::vector<std::vector<T>> mat;
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
        Array(int size, T value = 0) {
            std::vector<T> tmp;
            for (int i = 0; i < size; i++) {
                tmp.push_back(value);
            }
            arr = tmp;
        }
        Array(std::vector<T> arr_b) {
            arr = arr_b;
        }

        Array scalarAdd(T x) const {
            Array tmp = arr;
            for (size_t i = 0; i < tmp.arr.size(); i++) {
                tmp.arr[i] += x;
            }
            return tmp;
        }

        Array scalarSubtract(T x) const {
            Array tmp = arr;
            for (size_t i = 0; i < tmp.arr.size(); i++) {
                tmp.arr[i] -= x;
            }
            return tmp;
        }

        Array scalarMultiply(T x) const {
            Array tmp = arr;
            for (size_t i = 0; i < tmp.arr.size(); i++) {
                tmp.arr[i] *= x;
            }
            return tmp;
        }

        Array addArray(Array arr_y) const {
            Array tmp = arr;
            if (tmp.arr.size() != arr_y.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }

            for (size_t i = 0; i < tmp.arr.size(); i++) {
                tmp.arr[i] += arr_y.arr[i];
            }
            return tmp;
        }

        Array subtractArray(Array arr_y) const {
            Array tmp = arr;
            if (tmp.arr.size() != arr_y.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }

            for (size_t i = 0; i < tmp.arr.size(); i++) {
                tmp.arr[i] -= arr_y.arr[i];
            }
            return tmp;
        }

        Array multiplyArray(Array arr_y) const {
            Array tmp = arr;
            if (tmp.arr.size() != arr_y.arr.size()){
                throw std::invalid_argument("Length of vectors must the same!");
            }

            for (size_t i = 0; i < tmp.arr.size(); i++) {
                tmp.arr[i] *= arr_y.arr[i];
            }
            return tmp;
        }
        
        T operator[](int i) const {
            return arr[i];
        }

        void __setitem__(int i, T x) {
            arr[i] = x;
        }

        Array operator+(T x) const {
            return scalarAdd(x);
        }

        Array operator+=(T x) const {
            return scalarAdd(x);
        }

        Array operator-(T x) const {
            return scalarSubtract(x);
        }

        Array operator-=(T x) const {
            return scalarSubtract(x);
        }

        Array operator*(T x) const {
            return scalarMultiply(x);
        }

        Array operator*=(T x) const {
            return scalarMultiply(x);
        }

        Array operator+(Array vec) const {
            return addArray(vec);
        }

        Array operator+=(Array vec) const {
            return addArray(vec);
        }

        Array operator-(Array vec) const {
            return subtractArray(vec);
        }

        Array operator-=(Array vec) const {
            return subtractArray(vec);
        }

        Array operator*(Array vec) const {
            return multiplyArray(vec);
        }

        Array operator*=(Array vec) const {
            return multiplyArray(vec);
        }

        std::string toString() {
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
    m.doc() = "pybind11 example plugin"; // optional module docstring

    pybind11::class_<Matrix<int>>(m, "Matrix")
        .def(pybind11::init<std::vector<std::vector<int>>>())
        .def(pybind11::init<int, int, int>())
        .def(pybind11::init<int, int>())
        .def("getItem", &Matrix<int>::getItem)
        .def("getArray", &Matrix<int>::getArray)
        .def("setItem", &Matrix<int>::setItem)
        .def("setArray", &Matrix<int>::setArray)
        // .def("get", &Matrix<int>::get)
        .def("toString", &Matrix<int>::toString)
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
        .def(pybind11::self *= pybind11::self);
        
    pybind11::class_<Array<int>>(m, "Array")
        .def(pybind11::init<std::vector<int>>())
        .def(pybind11::init<int, int>())
        .def(pybind11::init<int>())
        .def("scalarAdd", &Array<int>::scalarAdd)
        .def("scalarSubtract", &Array<int>::scalarSubtract)
        .def("scalarMultiply", &Array<int>::scalarMultiply)
        .def("addArray", &Array<int>::addArray)
        .def("subtractArray", &Array<int>::subtractArray)
        .def("multiplyArray", &Array<int>::multiplyArray)
        .def("__getitem__", &Array<int>::operator[])
        .def("__setitem__", &Array<int>::__setitem__)
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
        .def("toString", &Array<int>::toString);

    // pybind11::class_<Array<double>>(m, "Array")
    //     .def(pybind11::init<std::vector<double>>())
    //     .def(pybind11::self + double());

    // pybind11::class_<Array<float>>(m, "Array")
    //     .def(pybind11::init<std::vector<float>>())
    //     .def(pybind11::self + float());

    m.def("setProcessors", &setProcessors, "A function that sets the number of processors for the library");
    m.def("getProcessors", &getProcessors, "A function that returns the number of processors set for the library");
    m.def("addInt", &addInt, "A function that adds two numbers");
    m.def("subtractInt", &subtractInt, "A function that subtracts two numbers");
    m.def("multiplyInt", &multiplyInt, "A function that multiplies two numbers");
    m.def("multiplyVectorMatrix", &multiplyVectorMatrix, "A function that does vector-matrix multiplication");
    m.def("addVectorVector", &addVectorVector, "A function that adds together values at equivalent indices between two vectors");
    m.def("subtractVectorVector", &subtractVectorVector, "A function that subtracts two values at equivalent indices between two vectors");
    m.def("multiplyVectorVector", &multiplyVectorVector, "A function that multiplies two values at equivalent indices between two vectors");
    m.def("scalarMatrixMultiply", &scalarMatrixMultiply, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixAdd", &scalarMatrixAdd, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarMatrixSubtract", &scalarMatrixSubtract, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarAddVector", &scalarAddVector, "A function that takes an integer, and performs scalar addition on a vector");
    m.def("scalarSubtractVector", &scalarSubtractVector, "A function that takes an integer, and performs scalar subtraction on a vector");
    m.def("scalarMultiplyVector", &scalarMultiplyVector, "A function that takes an integer, and performs scalar multiplication on a vector");
    m.def("multiplyMatrixMatrix", &multiplyMatrixMatrix, "A function that peforms matrix multiplication on two matrices of integers");
    m.def("addMatrixMatrix", &addMatrixMatrix, "A function that peforms matrix addition on two matrices of integers");
    m.def("subtractMatrixMatrix", &subtractMatrixMatrix, "A function that peforms matrix subtraction on two matrices of integers");
}
