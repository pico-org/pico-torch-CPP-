#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>

enum class DType {Float64, Float32, Int32};

//storage class
class Storage{
public:
    std::shared_ptr<std::vector<double>> data;
    size_t num_bytes;
};

class Tensor {
public:
    std::shared_ptr<Storage> storage;
    std::vector<int64_t> _strides;
    std::vector<int64_t> _shape;
    std::string _ops;
    std::vector<Tensor*> _parents;
    Tensor* _address;
    DType _dtype;
    std::shared_ptr<Tensor> _grad;
    bool requires_grad;

public:

    template <typename T>
    Tensor(const std::vector<T>& v, bool requires_grad = false);

    void data();
    void grad();
    std::vector<int64_t> shape();

    Tensor operator+(const Tensor& other) const;
    Tensor operator-(const Tensor& other) const;
    Tensor operator*(const Tensor& other) const;
    Tensor operator/(const Tensor& other) const;
};


template<typename T>
void processND(
    const T& x,
    std::vector<double>& _data,
    std::vector<int64_t>& _shape,
    int depth = 0
) {
    _data.push_back(x);
}

template<typename T>
void processND(
    const std::vector<T>& vec,
    std::vector<double>& _data,
    std::vector<int64_t>& _shape,
    int depth = 0
) {
    int64_t cnt = vec.size();

    if (_shape.size() <= depth)
        _shape.push_back(cnt);
    else
        _shape[depth] = cnt;

    for (const auto& x : vec) {
        processND(x, _data, _shape, depth + 1);
    }
}


template <typename T>
Tensor::Tensor(const std::vector<T>& v, bool requires_grad)
{
    this->storage = std::make_shared<Storage>();
    this->storage->data = std::make_shared<std::vector<double>>();

    processND(v, *this->storage->data, this->_shape);

    if (requires_grad) {
        size_t n = this->storage->data->size();
        std::vector<double> zeros(n, 0.0);

        this->_grad = std::make_shared<Tensor>(zeros, false);
    }

    this->requires_grad = requires_grad;
    this->_address = this;
}

#endif
