cmake_minimum_required(VERSION 3.16)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

#add_executable(algorithm main.cpp SortTestHelper.h InsertionSort.h MergeSort.h QuickSort.h QuickSort2Ways.h QuickSort3Ways.h)  # 第三章 排序算法
add_executable(algorithm heap.cpp SortTestHelper.h Heap.h InsertionSort.h MergeSort.h QuickSort.h QuickSort2Ways.h QuickSort3Ways.h HeapSort.h SelectionSort.h LocalHeapSort.h IndexMaxHeap.h)  # 第四章堆和堆排序