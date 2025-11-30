#include "tensor.hpp"
#include <iostream>
#include <vector>
using ll = long long;
using dd = double;

// for getting data
void Tensor::data() const {
    std::cout << "Tensor data: ";
    for(const auto& x : _data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// for getting size
void Tensor::size() const {
    std::cout << "Tensor Shape: ";
    std::cout << this->_data.size()<<"\n";
}


// for addition
Tensor Tensor::operator+(const Tensor& other) const {
    std::vector<int> vec(this->_data.size(),0);
    Tensor result(vec);
    if (this->_data.size() == other._data.size()) {
        result._data.resize(this->_data.size());
        for (size_t i = 0; i < this->_data.size(); ++i) {
            result._data[i] = this->_data[i] + other._data[i];
        }
    } else {
        std::cerr << "Error: Tensor sizes do not match for addition." << std::endl;
    }
    return result;
}