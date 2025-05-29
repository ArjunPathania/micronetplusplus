---

# Micronet++

A lightweight, modular C++ deep learning library built from scratch, designed for learning and experimenting with neural networks, tensor operations, and training algorithms.  
Integrated with Eigen3 for efficient linear algebra operations.

---

## Features

- Custom tensor data structures with efficient memory management
- Basic neural network components (layers, activation functions)
- Training utilities for simple tasks (e.g., XOR problem)
- Integration with [Eigen3](https://eigen.tuxfamily.org) via vcpkg for matrix operations
- Modular CMake build system with vcpkg support
- Unit testing framework integration (CTest)

---

## Getting Started

### Prerequisites

- C++17 compatible compiler (GCC, Clang, MSVC)
- [CMake](https://cmake.org/) 3.20 or higher
- [vcpkg](https://github.com/microsoft/vcpkg) for dependency management
- Eigen3 (installed via vcpkg)

### Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/micronetplusplus.git
cd micronetplusplus
````

Install dependencies with vcpkg:

```bash
./vcpkg install eigen3
```

### Build

Create a build directory and run CMake with the vcpkg toolchain:

```bash
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

### Run Tests / Examples

To run the test executable:

```bash
./test_tensor
```

To run the example training executable:

```bash
./train_xor
```

---

## Project Structure

```
micronet++/
├── src/               # Source code (tensor, neural nets, training)
├── tests/             # Unit tests
├── CMakeLists.txt     # Build configuration
├── README.md          # Project overview and instructions
└── vcpkg/             # vcpkg dependency manager (optional)
```

---

## Contributing

Contributions, issues, and feature requests are welcome! Feel free to fork the repository and submit pull requests.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contact

Created by \[Your Name] - \[[arjunpathania786f@gmail.com](mailto:arjunpathania786f@gmail.com)]
Project Link: [https://github.com/ArjunPathania/micronetplusplus](https://github.com/ArjunPathania/micronetplusplus)

```

---

If you want, I can help you customize this further with specific commands or add sections like roadmap, usage examples, or architecture overview!
```
