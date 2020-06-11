//
// Created by bohua on 2020/6/10.
//
#include <iostream>
#include <vector>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"

using namespace std;

int main() {

    // TestG1.txt - g1 and g2
    string filename = "D:\\Files\\codes\\cplusplus\\algorithm\\GraphBasics\\testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph1(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> dfs(g, 0);
    cout << "DFS: ";
    dfs.showPath(6);


    return 0;
}