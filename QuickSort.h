//
// Created by bohua on 2020/6/6.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <ctime>
#include <algorithm>
#include <iostream>
#include "InsertionSort.h"

template<typename T>
int __partition(T arr[], int l, int r) {
    // 随机选择中间点元素，避免二叉树不平衡
    swap(arr[l], arr[(rand() % (r - l + 1)) + l]);

    T v = arr[l];

    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < v) {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
//    if (l >= r) {
//        return;
//    }
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

// 快速排序
// !!!对近乎有序的数组，快排退化成了 O(n^2) 的算法
template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}
#endif //ALGORITHM_QUICKSORT_H
