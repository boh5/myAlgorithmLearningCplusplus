//
// Created by bohua on 2020/6/6.
//

#ifndef ALGORITHM_INSERTIONSORT_H
#define ALGORITHM_INSERTIONSORT_H
template<typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; ++i) {

//        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
//            swap(arr[j], arr[j - 1]);
//        }
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}
#endif //ALGORITHM_INSERTIONSORT_H
