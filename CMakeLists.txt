cmake_minimum_required(VERSION 3.12)
project(xgemm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=armv8-a+simd")

add_executable(gemm src/main.cpp)

