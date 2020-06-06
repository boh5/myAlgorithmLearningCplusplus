cmake_minimum_required(VERSION 3.16)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

#add_executable(algorithm main.cpp SortTestHelper.h Student.h)  # 第三章 排序算法
add_executable(algorithm heap.cpp SortTestHelper.h)  # 第四章堆和堆排序