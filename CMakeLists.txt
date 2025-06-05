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

# Find dependencies via Vcpkg
find_package(Eigen3 CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

# Add include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# Gather all sources and headers
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/**/*.hpp")

# Core library
add_library(micronet STATIC ${SOURCES} ${HEADERS})
target_link_libraries(micronet PRIVATE Eigen3::Eigen)

# =======================
# Executable: XOR training
# =======================
add_executable(train_xor src/train_xor.cpp)
target_link_libraries(train_xor PRIVATE micronet)

# =======================
# Unit Testing Setup
# =======================
enable_testing()

# Test executable using multiple test files
file(GLOB_RECURSE TEST_SOURCES
    "tests/test_*.cpp"
)

add_executable(micronet_tests ${TEST_SOURCES})
target_link_libraries(micronet_tests
    PRIVATE
        micronet
        GTest::gtest
        GTest::gtest_main
        fmt::fmt
)

include(GoogleTest)
gtest_discover_tests(micronet_tests)

# Add basic test check
add_test(NAME MicroNetUnitTests COMMAND micronet_tests)

# =======================
# Debug info
# =======================
message(STATUS "Project MicroNetPP configured with Eigen3, GTest, and fmt via vcpkg.")
