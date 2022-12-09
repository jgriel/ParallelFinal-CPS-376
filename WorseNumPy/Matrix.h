#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Matrix {
    public:
        // NOTE: crashes when n = 0
        Matrix(int rowSize, int colSize, T value);

        Matrix(std::vector<std::vector<T>> mat_b);

        std::string __repr__();

        Matrix addMatrix(Matrix const &m1) const;

        Matrix subtractMatrix(Matrix const &m1) const;

        Matrix multiplyMatrix(Matrix const &m1) const;

        Matrix scalarMultiply(T const &x) const;

        Matrix scalarAdd(T const &x) const;

        Matrix scalarSubtract(T const &x) const;


        //__getitem__
        T getItem(int i, int j);
        
        std::vector<T> getArray(int i);
        
        //set single element
        void setItem(int i, int j, T x);

        //set entire row
        void setArray(int i, std::vector<T> x);
        

        // Matrix scalar operations
        Matrix operator+(T a) const;

        Matrix operator+=(T a);

        Matrix operator-(T a) const;

        Matrix operator-=(T a);

        Matrix operator*(T a) const;
        
        Matrix operator*=(T a);

        // Matrix Matrix operations
        Matrix operator+(Matrix const &mat_b) const;

        Matrix operator+=(Matrix const &mat_b);

        Matrix operator-(Matrix const &mat_b) const;

        Matrix operator-=(Matrix const &mat_b);

        Matrix operator*(Matrix const &mat_b) const;

        Matrix operator*=(Matrix const &mat_b) const;
        // Matrix Vector Opertations

        std::vector<T> L1Norm();

        std::vector<float> L2Norm();

    private:
        std::vector<std::vector<T>> mat;
        int rows;
        int cols;
        std::string rowToString(std::vector<T> &row);
      
};

#endif