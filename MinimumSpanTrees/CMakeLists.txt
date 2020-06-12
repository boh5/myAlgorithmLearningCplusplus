cmake_minimum_required(VERSION 3.5)
project(MinimumSpanTrees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DenseGraph.h ReadGraph.h SparseGraph.h Edge.h MinHeap.h LazyPrimMST.h)
add_executable(MinimumSpanTrees ${SOURCE_FILES})