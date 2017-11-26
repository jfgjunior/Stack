#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include "Block.h"

template <class T>
class Stack {
private:
    std::vector< Block<T> > blocks;
    Block<T> *current;
public:
    Stack() {
        blocks.push_back( Block<T>(false) );
        current = &blocks.back();
    }

    T top(){
        return current->top();
    }

    T pop() {
        return current->pop();
    }

    void push(T value) {
        current->push(value);
    }

    bool rollback() {
        return current->rollback();
    }

    void begin() {
        blocks.push_back( Block<T>(true) );
        current = &blocks.back();
    }

    bool commit() {
        if( !current->getActive() )
            return false;

        Block<T> *aux = current;
        blocks.pop_back();
        current = &blocks.back();
        return current->commit(aux);
    }

    std::string toString() {
        return current->toString();
    }
};

#endif