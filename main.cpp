#include <iostream>
#include <vector>
#include "Sort/SortTestHelper.h"
#include "Sort/Student.h"
#include "Sort/InsertionSort.h"
#include "Sort/QuickSort.h"
#include "Sort/QuickSort2Ways.h"
#include "Sort/QuickSort3Ways.h"
#include "Sort/MergeSort.h"
#include "BinarySearchTree/BinarySearch.h"
#include "BinarySearchTree/BST.h"
#include "BinarySearchTree/FileOps.h"
#include "BinarySearchTree/SequenceST.h"

using namespace std;


int main() {
//    int n = 1000000;
//    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
//    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
//    SortTestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
//    cout << endl;
//    cout << binarySearch(arr1, n, 10000) << endl;
//    cout << binarySearch2(arr1, n, 10000) << endl;
//    cout << endl;
//
//    arr1 = SortTestHelper::generateNearlyOrderedArray(n, 100);
//    arr2 = SortTestHelper::copyIntArray(arr1, n);
//    arr3 = SortTestHelper::copyIntArray(arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
//    SortTestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
//    cout << endl;
//
//    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
//    arr2 = SortTestHelper::copyIntArray(arr1, n);
//    arr3 = SortTestHelper::copyIntArray(arr1, n);
//
////    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
//    SortTestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
//    cout << endl;
//
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;

    string filename = "D:\\Files\\codes\\cplusplus\\algorithm\\BinarySearchTree\\bible.txt";
    vector<string> words;

    if (FileOps::readFile(filename, words)) {
        cout << "There are totally " << words.size() << " words in " << filename;
        cout << endl;

        // test BST
        time_t startTime = clock();
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter < words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL) {
                bst.insert(*iter, 1);
            } else {
                (*res)++;
            }
        }
        cout << "'god': " << *bst.search("god") << endl;
        time_t endTime = clock();
        cout << "BST, time: " << double(endTime - startTime) / CLOCKS_PER_SEC;
        cout << endl;

        // test SST
        startTime = clock();
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter < words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL) {
                bst.insert(*iter, 1);
            } else {
                (*res)++;
            }
        }
        cout << "'god': " << *sst.search("god") << endl;
        endTime = clock();
        cout << "SST, time: " << double(endTime - startTime) / CLOCKS_PER_SEC;
        cout << endl;
    }

    return 0;
}
