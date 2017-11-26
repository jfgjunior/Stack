#ifndef NODE_H
#define NODE_H

#include <iostream>

typedef struct Node {
    
    int value;
    Node *right;
    Node *left;

    Node(int value) {
        this->value = value;
        right = NULL;
        left  = NULL;
    }
}Node;

#endif