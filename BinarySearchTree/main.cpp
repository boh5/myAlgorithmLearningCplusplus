#include <iostream>
#include <vector>
#include <ctime>
#include "BinarySearch.h"
#include "BST.h"
#include "FileOps.h"
#include "SequenceST.h"

using namespace std;


int main() {

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
