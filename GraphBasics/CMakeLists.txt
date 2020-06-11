cmake_minimum_required(VERSION 3.5)
project(GraphBasics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Component.h)
add_executable(GraphBasics ${SOURCE_FILES})