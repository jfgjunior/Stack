
#include "Stack.h"

using namespace std;

Stack::Stack() {
    blocks.push_back( Block(false) );
    current = &blocks.back();
}

int Stack::top(){
    return current->top();
}

int Stack::pop() {
    return current->pop();
}

void Stack::push(int value) {
    current->push(value);
}

bool Stack::rollback() {
    return current->rollback();
}

void Stack::begin() {
    blocks.push_back( Block(true) );
    current = &blocks.back();
}

bool Stack::commit() {
    if( !current->getActive() )
        return false;

    Block *aux = current;
    blocks.pop_back();
    current = &blocks.back();
    return current->commit(aux);
}

string Stack::toString() {
    return current->toString();
}