#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>

namespace micronet {

class Tensor {
public:
    Tensor(size_t rows, size_t cols);

    void set(size_t row, size_t col, float value);
    float get(size_t row, size_t col) const;

    size_t rows() const { return _rows; }
    size_t cols() const { return _cols; }

private:
    size_t _rows, _cols;
    std::vector<float> _data;
};

}  // namespace micronet
