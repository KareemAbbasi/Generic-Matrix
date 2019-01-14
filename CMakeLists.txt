cmake_minimum_required(VERSION 3.12)
project(cppEx3)

set(CMAKE_CXX_STANDARD 17)

include_directories($(EIGEN_DIR))

add_executable(cppEx3 Matrix.hpp Complex.cpp GenericMatrixDriver.cpp)