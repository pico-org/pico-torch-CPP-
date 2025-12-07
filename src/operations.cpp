#include "tensor.hpp"
#include <iostream>
#include <vector>
using ll = long long;
using dd = double;



// for additon
Tensor Tensor::operator+(const Tensor& other) const {
    const std::vector<double>& data_vector1 = *(this->storage->data);
    const std::vector<double>& data_vector2 = *(other.storage->data);

    if (data_vector1.size() != data_vector2.size()) {
        std::cerr << "Error Tensor sizes Miss-Match" << std::endl;
        return *this;
    }

    std::vector<double> vec(data_vector1.size(), 0.0);

    Tensor result(vec);

    for (size_t i = 0; i < data_vector1.size(); ++i) {
        (*(result.storage->data))[i] = data_vector1[i] + data_vector2[i];
    }

    result._parents.push_back(this->_address);
    result._parents.push_back(other._address);
    result._ops = "+";

    return result;
}




// // for substraction
Tensor Tensor::operator-(const Tensor& other) const {
    const std::vector<double>& data_vector1 = *(this->storage->data);
    const std::vector<double>& data_vector2 = *(other.storage->data);

    if (data_vector1.size() != data_vector2.size()) {
        std::cerr << "Error Tensor sizes Miss-Match" << std::endl;
        return *this;
    }

    std::vector<double> vec(data_vector1.size(), 0.0);

    Tensor result(vec);

    for (size_t i = 0; i < data_vector1.size(); ++i) {
        (*(result.storage->data))[i] = data_vector1[i] - data_vector2[i];
    }

    result._parents.push_back(this->_address);
    result._parents.push_back(other._address);
    result._ops = "+";

    return result;
}

Tensor Tensor::operator*(const Tensor& other) const {
    const std::vector<double>& data_vector1 = *(this->storage->data);
    const std::vector<double>& data_vector2 = *(other.storage->data);

    if (data_vector1.size() != data_vector2.size()) {
        std::cerr << "Error Tensor sizes Miss-Match" << std::endl;
        return *this;
    }

    std::vector<double> vec(data_vector1.size(), 0.0);

    Tensor result(vec);

    for (size_t i = 0; i < data_vector1.size(); ++i) {
        (*(result.storage->data))[i] = data_vector1[i] * data_vector2[i];
    }

    result._parents.push_back(this->_address);
    result._parents.push_back(other._address);
    result._ops = "+";

    return result;
}

Tensor Tensor::operator/(const Tensor& other) const {
    const std::vector<double>& data_vector1 = *(this->storage->data);
    const std::vector<double>& data_vector2 = *(other.storage->data);

    if (data_vector1.size() != data_vector2.size()) {
        std::cerr << "Error Tensor sizes Miss-Match" << std::endl;
        return *this;
    }

    std::vector<double> vec(data_vector1.size(), 0.0);

    Tensor result(vec);

    for (size_t i = 0; i < data_vector1.size(); ++i) {
        (*(result.storage->data))[i] = data_vector1[i] / data_vector2[i];
    }

    result._parents.push_back(this->_address);
    result._parents.push_back(other._address);
    result._ops = "+";

    return result;
}