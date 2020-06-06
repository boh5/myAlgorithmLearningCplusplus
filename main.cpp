#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"
#include "MergeSort.h"

using namespace std;




int main() {
    int n = 1000000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
    cout<<endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    arr1 = SortTestHelper::generateNearlyOrderedArray(n, 100);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
    cout<<endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

//    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
    cout<<endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
