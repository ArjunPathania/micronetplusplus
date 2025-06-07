#ifndef MATRIX_OPS_HPP
#define MATRIX_OPS_HPP

#include <Eigen/Dense>
#include <iostream>
#include <random>

namespace dl {

using Matrix = Eigen::MatrixXd;
using Vector = Eigen::VectorXd;

class MatrixOps {
public:
    // Matrix multiplication: A * B
    static Matrix dot(const Matrix& A, const Matrix& B) {
        return A * B;
    }

    // Element-wise multiplication
    static Matrix multiply(const Matrix& A, const Matrix& B) {
        return A.array() * B.array();
    }

    // Element-wise division
    static Matrix divide(const Matrix& A, const Matrix& B) {
        return A.array() / B.array();
    }

    // Element-wise power
    static Matrix power(const Matrix& A, double exponent) {
        return A.array().pow(exponent);
    }

    // Transpose of matrix
    static Matrix transpose(const Matrix& A) {
        return A.transpose();
    }

    // Apply a function element-wise (e.g., ReLU, sigmoid)
    static Matrix applyFunction(const Matrix& A, const std::function<double(double)>& func) {
        return A.unaryExpr(func);
    }

    // Apply derivative of a function element-wise (e.g., ReLU', sigmoid')
    static Matrix applyDerivative(const Matrix& A, const std::function<double(double)>& dfunc) {
        return A.unaryExpr(dfunc);
    }

    // Initialize random matrix with normal distribution
    static Matrix randomNormal(int rows, int cols, double mean = 0.0, double stddev = 1.0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(mean, stddev);

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = d(gen);

        return result;
    }

    // Sum across rows or columns
    static Matrix sum(const Matrix& A, int axis = 0) {
        if (axis == 0) // column-wise sum → row vector
            return A.colwise().sum();
        else // row-wise sum → column vector
            return A.rowwise().sum();
    }

    // Mean across rows or columns
    static Matrix mean(const Matrix& A, int axis = 0) {
        if (axis == 0)
            return A.colwise().mean();
        else
            return A.rowwise().mean();
    }

    // Broadcast vector to match matrix dimensions
    static Matrix broadcastTo(const Vector& vec, int rows, bool vertical = true) {
        if (vertical) // broadcast row-wise
            return vec.replicate(1, rows).transpose();
        else // broadcast column-wise
            return vec.replicate(1, rows);
    }
};

} // namespace dl

#endif // MATRIX_OPS_HPP
