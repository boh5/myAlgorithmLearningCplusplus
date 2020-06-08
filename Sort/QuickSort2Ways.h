//
// Created by bohua on 2020/6/6.
//

#ifndef ALGORITHM_QUICKSORT2WAYS_H
#define ALGORITHM_QUICKSORT2WAYS_H

#include <ctime>
#include <algorithm>
#include <iostream>
#include "InsertionSort.h"

template<typename T>
int __partition2(T arr[], int l, int r) {
    // 随机选择中间点元素，避免二叉树不平衡
    swap(arr[l], arr[(rand() % (r - l + 1)) + l]);
    T v = arr[l];

    // arr[l+1,i) <=v; arr(j,r] >=v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l + 1 && arr[j] > v) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    swap(arr[l], arr[j]);

    return j;
}

template<typename T>
void __quickSort2(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p - 1);
    __quickSort2(arr, p + 1, r);
}

// 快速排序
// !!!对近乎有序的数组，快排退化成了 O(n^2) 的算法
template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n - 1);
}
#endif //ALGORITHM_QUICKSORT2WAYS_H
