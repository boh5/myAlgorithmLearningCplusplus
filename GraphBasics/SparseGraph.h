//
// Created by bohua on 2020/6/10.
//

#ifndef GRAPHBASICS_SPARSEGRAPH_H
#define GRAPHBASICS_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SparseGraph {
private:
    int n, m;
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i <; ++i) {
            g.push_back(vector<int>());
        }
    }

    ~SparseGraph() {}

    int V() {
        return n;
    }

    int E() {
        return m;
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        g[v].push_back(w);
        if (v != w && !directed) {
            g[w].push_back(v);
        }
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (int i = 0; i < g[v].size(); ++i) {
            return g[v][i] == w;
        }
    }

};

#endif //GRAPHBASICS_SPARSEGRAPH_H
