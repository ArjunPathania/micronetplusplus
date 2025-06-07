cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0077 NEW)

project(MicroNetPP VERSION 0.1.0 LANGUAGES CXX)

# ================================
# Modern C++ Setup
# ================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ================================
# Vcpkg Toolchain Setup
# ================================
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# ================================
# Dependencies via Vcpkg
# ================================
find_package(Eigen3 CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

# ================================
# Core Library: micronet
# ================================
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/**/*.hpp")

add_library(micronet STATIC ${SOURCES} ${HEADERS})
target_link_libraries(micronet PRIVATE Eigen3::Eigen)

target_include_directories(micronet
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(micronet PUBLIC cxx_std_17)

target_compile_options(micronet PRIVATE
    -Wall -Wextra -Wpedantic -Werror
)

# ================================
# Executable: Unit Tests
# ================================
include(CTest)
enable_testing()

file(GLOB_RECURSE TEST_SOURCES "tests/test_*.cpp")

add_executable(micronet_tests ${TEST_SOURCES})
target_link_libraries(micronet_tests
    PRIVATE
        micronet
        GTest::gtest
        GTest::gtest_main
        fmt::fmt
)

include(GoogleTest)

# ✅ Important fix: ensure test discovery works reliably
gtest_discover_tests(micronet_tests DISCOVERY_TIMEOUT 30)

# ================================
# Debug Info
# ================================
message(STATUS "MicroNetPP configured with:")
message(STATUS "  - C++17 and extensions OFF")
message(STATUS "  - Eigen3, GTest, and fmt via Vcpkg")
message(STATUS "  - Tests discovered using gtest_discover_tests")
