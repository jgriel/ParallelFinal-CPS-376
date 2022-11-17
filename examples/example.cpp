#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

// To compile c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)


// 1d array create our array type (like numpy.array([1, 2, 3]))
std::vector<int> array(std::vector<int> arr_a) {
    std::vector<int> arr_b;
    for (size_t i = 0; i < arr_a.size(); i++) {
        arr_b.push_back(arr_a[i]);
    }
    return arr_b;
}

// 2d array create our array type (like numpy.array([1, 2, 3]))
std::vector<std::vector<int>> array(std::vector<std::vector<int>> arr_a) {
    std::vector<std::vector<int>> arr_b;
    for (size_t i = 0; i < arr_a.size(); i++) {
        arr_b.push_back({});
        for (size_t j = 0; j < arr_a.size(); j++) {
           arr_b[i].push_back(arr_a[i][j]);
        }
        
    }
    return arr_b;
}

int add(int i, int j) {
    return i + j;
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

std::vector<std::vector<int>> scalarMatrix(int x, std::vector<std::vector<int>> mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j] *= x;
        }
    }
    return mat;
}

std::vector<int> scalarVector(int x, std::vector<int> arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] *= x;
    }
    return arr;
}

int subtractInt(int i, int j) {
    return i - j;
}

int multiplyInt(int i, int j) {
    return i * j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("array", &array<std::vector<int>> arr_a>, "A function that creates a 1d array within our library");
    m.def("array", &array<std::vector<std::vector<int>> arr_a>, "A function that creates a 2d array within our library");    
    m.def("add", &add, "A function that adds two numbers");
    m.def("multiplyVectorMatrix", &multiplyVectorMatrix, "A function that does vector-matrix multiplication");
    m.def("addVectorVector", &addVectorVector, "A function that adds together values at equivalent indices between two vectors");
    m.def("subtractVectorVector", &subtractVectorVector, "A function that subtracts two values at equivalent indices between two vectors");
    m.def("multiplyVectorVector", &multiplyVectorVector, "A function that multiplies two values at equivalent indices between two vectors");
    m.def("scalarMatrix", &scalarMatrix, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarVector", &scalarVector, "A function that takes an integer, and performs scalar multiplication on a vector");
    m.def("subtract", &subtractInt, "A function that subtracts two numbers");
    m.def("multiply", &multiplyInt, "A function that multiplies two numbers");
}
