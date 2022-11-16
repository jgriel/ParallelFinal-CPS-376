#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

// To compile c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)

int add(int i, int j) {
    return i + j;
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
    m.def("add", &add, "A function that adds two numbers");
    m.def("scalarMatrix", &scalarMatrix, "A function that performs scalar multiplication between an integer and a matrix of integers");
    m.def("scalarVector", &scalarVector, "A function that takes an integer, and performs scalar multiplication on a vector");
    m.def("subtract", &subtractInt, "A function that subtracts two numbers");
    m.def("multiply", &multiplyInt, "A function that multiplies two numbers");
}
