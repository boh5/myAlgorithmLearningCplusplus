//
// Created by bohua on 2020/6/6.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

#include "InsertionSort.h"

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    // 大数组用 new 生成，delete[] 删除
//    T aux[r - l + 1];
    T *aux = new T[r - l + 1];
    for (int i = l; i <= r; ++i) {
        aux[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else {
            if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }
    }
    delete[] aux;
}

template<typename T>
void __mergeSort(T arr[], int l, int r) {

//    if (l >= r) {
//        return;
//    }

    // 优化1：小数据用插入排序，不再递归
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    // 优化2：如果 mid 比 mid + 1 还小，说明该子序列已经有序，不再需要 merge 操作
    if (arr[mid] > arr[mid + 1]) {
        __merge(arr, l, mid, r);
    }
}

// 归并排序
template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

#endif //ALGORITHM_MERGESORT_H
