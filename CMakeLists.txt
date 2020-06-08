cmake_minimum_required(VERSION 3.16)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp Sort/SortTestHelper.h Sort/InsertionSort.h Sort/MergeSort.h Sort/QuickSort.h Sort/QuickSort2Ways.h Sort/QuickSort3Ways.h BinarySearchTree/BinarySearch.h BinarySearchTree/BST.h)
