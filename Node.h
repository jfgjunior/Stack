#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
struct Node {
    
    T value;
    Node<T> *right;
    Node<T> *left;

    Node<T>(T value) {
        this->value = value;
        right = NULL;
        left  = NULL;
    }
};

#endif