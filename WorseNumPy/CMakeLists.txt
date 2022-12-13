cmake_minimum_required(VERSION 3.4...3.18)
project(WorseNumPy)

find_package(OpenMP)
add_subdirectory(pybind11)
pybind11_add_module(WorseNumPy src/WorseNumPy.cpp)
target_link_libraries(WorseNumPy PUBLIC OpenMP::OpenMP_CXX)
