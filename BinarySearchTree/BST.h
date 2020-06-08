//
// Created by bohua on 2020/6/8.
//

#ifndef ALGORITHM_BST_H
#define ALGORITHM_BST_H

#include <iostream>

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
        }

    };

    Node *root;
    int count;

public:
    BST() {
        root = NULL;
        count = 0;
    }
    ~BST() {
        // TODO
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};

#endif //ALGORITHM_BST_H
