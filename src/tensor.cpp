#include "../include/micro/tensor.hpp"

namespace micronet {

Tensor::Tensor(size_t rows, size_t cols)
    : _rows(rows), _cols(cols), _data(rows * cols, 0.0f) {}

void Tensor::set(size_t row, size_t col, float value) {
    if (row >= _rows || col >= _cols)
        throw std::out_of_range("Tensor index out of range.");
    _data[row * _cols + col] = value;
}

float Tensor::get(size_t row, size_t col) const {
    if (row >= _rows || col >= _cols)
        throw std::out_of_range("Tensor index out of range.");
    return _data[row * _cols + col];
}

}  // namespace micronet
