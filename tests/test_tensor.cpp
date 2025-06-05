#include <gtest/gtest.h>
#include "../include/micro/tensor.hpp"

using namespace micronet;

TEST(TensorTest, SetGetWorks) {
    Tensor t(2, 3);
    t.set(0, 0, 1.5f);
    t.set(1, 2, -3.2f);

    EXPECT_FLOAT_EQ(t.get(0, 0), 1.5f);
    EXPECT_FLOAT_EQ(t.get(1, 2), -3.2f);
}

TEST(TensorTest, OutOfBoundsThrows) {
    Tensor t(2, 2);
    EXPECT_THROW(t.set(2, 0, 5.0f), std::out_of_range);
    EXPECT_THROW(t.get(0, 2), std::out_of_range);
}
