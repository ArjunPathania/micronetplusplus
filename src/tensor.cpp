// tensor.cpp

#include "../include/micro/tensor.hpp"
#include <numeric>
#include <stdexcept>

// Constructor that initializes with shape and optional initial value
Tensor::Tensor(const std::vector<size_t>& shape_, float init_val) 
    : shape(shape_) {
    size_t total = 1;
    for (size_t s : shape) total *= s;
    data.resize(total, init_val);
}

// Helper: convert multi-dimensional indices to a flat index (not used in simple version)
size_t Tensor::flatten_index(const std::vector<size_t>& indices) const {
    if (indices.size() != shape.size()) {
        throw std::invalid_argument("Incorrect number of indices");
    }
    size_t idx = 0;
    size_t stride = 1;
    for (int i = static_cast<int>(shape.size()) - 1; i >= 0; --i) {
        if (indices[i] >= shape[i]) {
            throw std::out_of_range("Index out of bounds");
        }
        idx += indices[i] * stride;
        stride *= shape[i];
    }
    return idx;
}

// Print tensor shape
void Tensor::print_shape() const {
    std::cout << "Tensor shape: (";
    for (size_t i = 0; i < shape.size(); ++i) {
        std::cout << shape[i];
        if (i < shape.size() - 1) std::cout << ", ";
    }
    std::cout << ")\n";
}

// Print tensor data
void Tensor::print_data() const {
    std::cout << "Tensor data: ";
    for (float val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
