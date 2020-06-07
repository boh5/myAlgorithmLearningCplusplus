//
// Created by bohua on 2020/6/6.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include "SortTestHelper.h"

#include "Heap.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort3Ways.h"
#include "HeapSort.h"

template<typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 < n) {

        int j = 2 * k + 1;  // arr[k] 和 arr[j] 交换位置
        if (j + 1 < n && arr[j + 1] > arr[j]) {
            j++;
        }
        if (arr[k] >= arr[j]) {
            break;
        }
        swap(arr[k], arr[j]);
        k = j;
    }
}

template<typename T>
void heapSort(T arr[], int n) {

    // heapify
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }


    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

int main() {
    int n = 1000000;

    cout << "Test for Random Array, size = " << n << ", random range [0," << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int *arr6 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    return 0;
}