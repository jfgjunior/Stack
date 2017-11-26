#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include "Block.h"

class Stack {
private:
    std::vector<Block> blocks;
    Block *current;
public:
    Stack();
    int top();
    int pop();
    void push(int);

    void begin();
    bool rollback();
    bool commit();
    std::string toString();
};

#endif