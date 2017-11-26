
#include "Block.h"

using namespace std;

Block::Block(bool active) {
    this->active = active;
    first = NULL;
    bottom = NULL;
}

void Block::push(int value) {
    if(active)
        commands.push_back(Command(PUSH, value));

    if(first) {
        Node *aux = first;
        first->right = new Node(value);
        first = first->right;
        first->left = aux;
    } else {
        first = new Node(value);
        bottom = first;
    }
}

int Block::top() {
    if(active)
        commands.push_back( Command(TOP) );

    if(first)
        return first->value;
    return 0;
}

int Block::pop() {
    if(active)
        commands.push_back( Command( PUSH, top() ) );

    if(first) {
        int value = top();
        Node *aux = first;
        first = first->left;
        delete aux;
        return value;
    }
    return 0;
}

bool Block::rollback() {
    if(!active)
        return false;
    
    if(!commands.empty()) {
        Command command = commands.back();
        commands.pop_back();

        switch(command.command) {
            case PUSH: 
                pop();
                break;
            case POP:
                push(command.value);
                break;
        }
        return true;
    }
    return false;
}

bool Block::commit(Block *topBlock) {
    if( topBlock->getTop() ) {
        first->right = topBlock->getBottom();
        first = topBlock->getTop();
        return true;
    }
    return false;
}

bool Block::getActive() {
    return active;
}

Node *Block::getBottom() {
    return bottom;
}

Node *Block::getTop() {
    return first;
}

string Block::toString() {
    if(first) {
        stringstream ss;
        Node *it = bottom;
        ss << "Stack: ";
        while(it != first) {
            ss << it->value << " - ";
            it = it->right;
        }
        ss << it->value;
        return ss.str();
    }
    return "";
}