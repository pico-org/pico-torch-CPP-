#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iostream>
#include <vector>
#include <string>

class Tensor {
// elements of tensor
public:
    std::vector<double> _data;
    std::vector<int> _strides;
    std::string _ops;
    std::vector<Tensor*> _parents;
    Tensor* address;
    
    template <typename T>
    Tensor(const std::vector<T>& v);  
    
    void data() const;
    void size() const;
    
    Tensor operator+(const Tensor& other) const;
    Tensor operator-(const Tensor& other) const;
    Tensor operator*(const Tensor& other) const;
    Tensor operator/(const Tensor& other) const;

};

// helper func for reading ND array
template<typename T>
void processND(const T& x, std::vector<double>& _data) {
    _data.push_back(x);
}

template<typename T>
void processND(const std::vector<T>& vec, std::vector<double>& _data) {
    for(const auto& x : vec) {
        processND(x, _data);
    }
}

// constructer
// parameter: A ND vector
template <typename T>
Tensor::Tensor(const std::vector<T>& v) {       
    processND(v, this->_data);
    this->address = this;
}




#endif 