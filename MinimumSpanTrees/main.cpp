//
// Created by bohua on 2020/6/12.
//

#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"

int main() {
    string filename = "D:\\Files\\codes\\cplusplus\\algorithm\\MinimumSpanTrees\\testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g, filename);
    g.show();
    cout << endl;

    cout << "Test Lazy Prim MST:" << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i) {
        cout << mst[i] << endl;
    }
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;
    cout << endl;

    return 0;
}