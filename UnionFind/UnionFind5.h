//
// Created by bohua on 2020/6/10.
//

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H

#include <cassert>

namespace UF5 {
    class UnionFind {
    private:
        int *parent;
        int *rank;
        int count;

    public:
        UnionFind(int count) {
            this->count = count;
            rank = new int[count];
            parent = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert (p >= 0 && p < count);
//            while (p != parent[p]) {
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;
            if (p != parent[p]) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {

            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot) {
                return;
            }
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[qRoot] < rank[pRoot]) {
                parent[qRoot] = pRoot;
            } else {
                parent[pRoot] = qRoot;
                rank[qRoot]++;
            }
        }
    };
}

#endif //UNIONFIND_UNIONFIND5_H
