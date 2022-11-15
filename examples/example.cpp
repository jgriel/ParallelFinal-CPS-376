#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

// To compile c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)

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

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
    m.def("multiplyVectorMatrix", &multiplyVectorMatrix, "A function that does vector-matrix multiplication");
}
