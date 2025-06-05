// tensor.hpp
#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <iostream>
#include <cassert>
#include <cstddef>

class Tensor {
private:
    std::vector<size_t> shape;
    std::vector<float> data;

    // Convert multi-dimensional index to flat index
    size_t flatten_index(const std::vector<size_t>& indices) const;

public:
    // Constructors
    Tensor() = default;
    Tensor(const std::vector<size_t>& shape_, float init_val = 0.0f);

    // Accessors
    const std::vector<size_t>& get_shape() const { return shape; }
    size_t size() const { return data.size(); }
    const std::vector<float>& get_data() const { return data; }

    // Flat indexing operator
    float& operator[](size_t idx) {
        assert(idx < data.size());
        return data[idx];
    }

    const float& operator[](size_t idx) const {
        assert(idx < data.size());
        return data[idx];
    }

    // Print utilities
    void print_shape() const;
    void print_data() const;
};

#endif // TENSOR_HPP
