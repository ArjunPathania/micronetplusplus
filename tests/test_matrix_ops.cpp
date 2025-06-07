#include <gtest/gtest.h>
#include "../include/micro/matrix_ops.hpp"

using namespace dl;

TEST(MatrixOpsTest, DotProduct) {
    Matrix A(2, 3);
    Matrix B(3, 2);

    A << 1, 2, 3,
         4, 5, 6;

    B << 1, 4,
         2, 5,
         3, 6;

    Matrix expected(2, 2);
    expected << 14, 32,
                32, 77;

    Matrix result = MatrixOps::dot(A, B);
    EXPECT_LT((result - expected).norm(), 1e-9);
}

TEST(MatrixOpsTest, ElementWiseMultiply) {
    Matrix A(2, 2);
    A << 1, 2,
         3, 4;

    Matrix B(2, 2);
    B << 5, 6,
         7, 8;

    Matrix expected(2, 2);
    expected << 5, 12,
                21, 32;

    Matrix result = MatrixOps::multiply(A, B);
    EXPECT_LT((result - expected).norm(), 1e-9);
}

TEST(MatrixOpsTest, ApplyFunctionRelu) {
    Matrix A(2, 2);
    A << -1, 0,
          2, -3;

    Matrix expected(2, 2);
    expected << 0, 0,
                2, 0;

    auto relu = [](double x) { return x > 0 ? x : 0; };

    Matrix result = MatrixOps::applyFunction(A, relu);
    EXPECT_LT((result - expected).norm(), 1e-9);
}
