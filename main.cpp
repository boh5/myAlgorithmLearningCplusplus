#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; ++i) {

//        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
//            swap(arr[j], arr[j - 1]);
//        }
        T e = arr[i];
        int j;
        for (j = i;  j > 0 && arr[j-1] > e ; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}


int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    delete[] arr;
    delete[] arr2;

    return 0;
}
