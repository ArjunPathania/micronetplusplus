cmake_minimum_required(VERSION 3.15)
project(MicroNetPP LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()


find_package(Eigen3 CONFIG QUIET)
if(NOT Eigen3_FOUND)
    message(STATUS "Eigen3 not found via vcpkg. Using extern/eigen")
    include_directories(extern/eigen)
else()
    message(STATUS "Eigen3 found via vcpkg")
endif()


include_directories(include)


file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/**/*.hpp")

# Static library from source
add_library(micronet STATIC ${SOURCES} ${HEADERS})

# Link Eigen if found via vcpkg
if(Eigen3_FOUND)
    target_link_libraries(micronet PRIVATE Eigen3::Eigen)
endif()

# Add executable: train_xor
add_executable(train_xor src/train_xor.cpp)
target_link_libraries(train_xor PRIVATE micronet)

# Add executable: test_tensor (unit tests)
add_executable(test_tensor tests/test_tensor.cpp)
target_link_libraries(test_tensor PRIVATE micronet)

# Enable and register test
enable_testing()
add_test(NAME TensorTest COMMAND test_tensor)
