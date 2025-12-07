#include "tensor.hpp"
#include <iostream>
#include <vector>
using ll = long long;
using dd = double;

void Tensor::data() {
    for (auto x : *(this->storage->data)) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

std::vector<int64_t> Tensor::shape(){
    return this->_shape;
}

void Tensor::grad() {
    if (!this->_grad) {
        std::cout << "Gradient is NULL\n";
        return;
    }

    this->_grad->data();  
}
