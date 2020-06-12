//
// Created by bohua on 2020/6/12.
//

#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

int main () {
    string filename = "D:\\Files\\codes\\cplusplus\\algorithm\\MinimumSpanTrees\\testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);

    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;

    return 0;
}