
cmake_minimum_required(VERSION 3.5)
project(BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BinarySearch.h BST.h SequenceST.h FileOps.h BSTTraverse.h BSTLevelTraverse.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(04_Binary_Search_Tree_Search ${SOURCE_FILES})