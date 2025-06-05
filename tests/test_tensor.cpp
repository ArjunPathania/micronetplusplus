#include "../src/tensor.cpp"

int main() {
    Tensor t({2, 3});  // 2x3 tensor
    t[0] = 1.0f;
    t[1] = 2.0f;
    t[5] = 3.0f;

    t.print_shape();
    t.print_data();

    return 0;
}
