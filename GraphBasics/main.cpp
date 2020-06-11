//
// Created by bohua on 2020/6/10.
//
#include <iostream>
#include <vector>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main() {

    string filename = "D:\\Files\\codes\\cplusplus\\algorithm\\GraphBasics\\testG1.txt";
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();

    cout<<endl;

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    g2.show();

    return 0;
}