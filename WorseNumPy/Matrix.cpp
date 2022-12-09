#include <omp.h>
#include <iostream>
#include <string>
#include <vector>
#include "Matrix.h"

// template <typename T>
// NOTE: crashes when n = 0
template<typename T>
Matrix<T>::Matrix(int rowSize, int colSize, T value) {
    rows = rowSize;
    cols = colSize;
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

template<typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> mat_b) {
    rows = mat_b.size();
    if (mat_b.size() > 0) {
        cols = mat_b[0].size();
    }
    else {
        cols = 0;
    }
    mat = mat_b;
}

template<typename T>
std::string Matrix<T>::__repr__() {
    std::string msg = "[";
    for (size_t i = 0; i < mat.size() - 1; i++) {
        msg += rowToString(mat[i]) + ", ";
    }

    msg += rowToString(mat[mat.size() - 1]) + "]";
    return msg;
}

template<typename T>
Matrix<T> Matrix<T>::addMatrix(Matrix const &m1) const{
    Matrix m3 = Matrix(mat.size(), mat[0].size(), 0);
    if (mat.size() != m1.mat.size()) {
        throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
    }
    #pragma omp parallel for
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

template<typename T>
Matrix<T> Matrix<T>::subtractMatrix(Matrix const &m1) const{
    Matrix m3 = Matrix(mat.size(), mat[0].size(), 0);
    if (mat.size() != m1.mat.size()) {
        throw std::invalid_argument("Size of Matrix #1 and Matrix #2 must be the same!");
    }
    #pragma omp parallel for
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

template<typename T>
Matrix<T> Matrix<T>::multiplyMatrix(Matrix const &m1) const {
    Matrix tmp_mat = Matrix(mat.size(), m1.mat[0].size(), 0);
    #pragma omp parallel for
        for (size_t mat_row = 0; mat_row < mat.size(); mat_row++) {
            if (mat[mat_row].size() != m1.mat.size()) {
                throw std::invalid_argument("Columns in each row of matrix #1 must equal length of the number of rows in matrix #2!");
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

template<typename T>
Matrix<T> Matrix<T>::scalarMultiply(T const &x) const {
    Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
    #pragma omp parallel for
        for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
            for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                tmp_mat.mat[i][j] = mat[i][j] * x;
            }
        }
    return tmp_mat;
}

template<typename T>
Matrix<T> Matrix<T>::scalarAdd(T const &x) const {
    Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
    #pragma omp parallel for
        for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
            for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                tmp_mat.mat[i][j] = mat[i][j] + x;
            }
        }
    return tmp_mat;
}

template<typename T>
Matrix<T> Matrix<T>::scalarSubtract(T const &x) const {
    Matrix tmp_mat = Matrix(mat.size(), mat[0].size(), 0);
    #pragma omp parallel for
        for (size_t i = 0; i < tmp_mat.mat.size(); i++) {
            for (size_t j = 0; j < tmp_mat.mat[i].size(); j++) {
                tmp_mat.mat[i][j] = mat[i][j] - x;
            }
        }
    return tmp_mat;
}

// Matrix multiplyVectorMatrix(Array arr) {
//     Matrix mat_b = Matrix(0, 0);
//     for (size_t i = 0; i < mat.size(); i++) {
//         if (arr.size() != mat[i].size()) {
//             throw std::invalid_argument("Length of all rows in the matrix must == length of the vector!");
//         }

//         mat_b.mat.push_back({});
//         for (size_t j = 0; j < mat[i].size(); j++) {
//             mat_b.mat[i].push_back(arr[j] * mat[i][j]);
//         }
//     }
//     return mat_b;
// }

//__getitem__
template<typename T>
T Matrix<T>::getItem(int i, int j) {
    return mat[i][j];
}

template<typename T>
std::vector<T> Matrix<T>::getArray(int i) {
    return mat[i];
}

//set single element
template<typename T>
void Matrix<T>::setItem(int i, int j, T x) {
    mat[i][j] = x;
}

//set entire row
template<typename T>
void Matrix<T>::setArray(int i, std::vector<T> x) {
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
template<typename T>
Matrix<T> Matrix<T>::operator+(T a) const {
    return scalarAdd(a);
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(T a) {
    #pragma omp parallel for
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = mat[i][j] + a;
            }
        }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(T a) const {
    return scalarSubtract(a);
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(T a) {
    #pragma omp parallel for
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = mat[i][j] - a;
            }
        }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T a) const {
    return scalarMultiply(a);
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(T a) {
    #pragma omp parallel for
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = mat[i][j] * a;
            }
        }
    return *this;
}

// Matrix Matrix operations
template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix const &mat_b) const {
    return addMatrix(mat_b);
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(Matrix const &mat_b) {
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

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix const &mat_b) const {
    return subtractMatrix(mat_b);
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(Matrix const &mat_b) {
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

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix const &mat_b) const {
    return multiplyMatrix(mat_b);
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(Matrix const &mat_b) const {
    return multiplyMatrix(mat_b);
}

// Matrix Vector Opertations
template<typename T>
std::vector<T> Matrix<T>::L1Norm() {
    std::vector<T> normVec = {};
    for (int col = 0; col < cols; col++) {
        T curNorm = 0;
        for (int row = 0; row < rows; row++) {
            curNorm += abs(mat[row][col]);
        }
        normVec.push_back(curNorm);
    }
    return normVec;
}

template<typename T>
std::vector<float> Matrix<T>::L2Norm() {
    std::vector<float> normVec = {};
    for (int col = 0; col < cols; col++) {
        T acc = 0;
        for (int row = 0; row < rows; row++) {
            acc += pow(mat[row][col], 2);
        }
        normVec.push_back(sqrt(acc));
    }
    return normVec;
}

// Can probably delete but need to confirm with McDanel if the above norm methods are what he wants.

// T L1Norm() {
//     T maxNorm = 0;
//     for (int col = 0; col < cols; col++) {
//         T curNorm = 0;
//         for (int row = 0; row < rows; row++) {
//             curNorm += abs(mat[row][col]);
//         }
//         if (curNorm > maxNorm) {
//             maxNorm = curNorm;
//         }
//     }
//     return maxNorm;
// }


// std::vector<float> norm(int normType) {
//     std::vector<float> normVec = {};
//     // L1
//     if (normType == 1) {
//         for (int col = 0; col < cols; col++) {
//             T curNorm = 0;
//             for (int row = 0; row < rows; row++) {
//                 curNorm += abs(mat[row][col]);
//             }
//             normVec.push_back(curNorm);
//         }
//     }
//     // L2
//     else if (normType == 2) {
//         for (int col = 0; col < cols; col++) {
//             T acc = 0;
//             for (int row = 0; row < rows; row++) {
//                 acc += pow(mat[row][col], 2);
//             }
//             normVec.push_back(sqrt(acc));
//         }
//     }
//     else {
//         throw std::invalid_argument("Norm type must be 1 (L1Norm) or 2 (L2Norm)!");
//     }

//     return normVec;
// }
template <typename T>
std::vector<std::vector<T>> mat;
int rows;
int cols;
template <typename T>
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

