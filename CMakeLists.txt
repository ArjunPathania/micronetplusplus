cmake_minimum_required(VERSION 3.15)
project(MicroNetPP VERSION 0.1.0 LANGUAGES CXX)

# Enforce modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vcpkg toolchain setup
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# Find Eigen from vcpkg
find_package(Eigen3 CONFIG REQUIRED)

# Add include dirs
include_directories(
    ${EIGEN3_INCLUDE_DIRS} # Usually redundant, but helps with intellisense sometimes
    ${PROJECT_SOURCE_DIR}/include
)

# Gather all sources and headers
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/**/*.hpp")

# Core static library
add_library(micronet STATIC ${SOURCES} ${HEADERS})
target_link_libraries(micronet PRIVATE Eigen3::Eigen)

# Executable: XOR training
add_executable(train_xor src/train_xor.cpp)
target_link_libraries(train_xor PRIVATE micronet)

# Executable: Tensor test
add_executable(test_tensor tests/test_tensor.cpp)
target_link_libraries(test_tensor PRIVATE micronet)

# Unit testing support
enable_testing()
add_test(NAME TensorTest COMMAND test_tensor)

# Messages for clarity
message(STATUS "Project MicroNetPP configured with Eigen3 via vcpkg.")
