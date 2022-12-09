#include <iostream>
#include <string>
#include <vector>

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
        
        T getItem(int i) {
            return arr[i];
        }

        void setItem(int i, T x) {
            arr[i] = x;
        }

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

        T L1Norm() {
            T acc = 0;
            for (T element : arr) {
                acc += abs(element);
            }
            return acc;
        }

        float L2Norm() {
            T acc = 0;
            for (T element : arr) {
                acc += pow(element, 2);
            }
            float ans = sqrt(acc);
            return ans;
        }

    private:
        std::vector<T> arr;
      
};
