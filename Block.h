#ifndef BLOCK_H
#define BLOCK_H

#include "Node.h"
#include "Command.h"
#include <vector>
#include "Common.h"
#include "sstream"

template <class T>
class Block {
private:
    Node<T> *first;
    Node<T> *bottom;
    std::vector< Command<T> > commands;
    bool active;

public:
    Block<T>(bool active) {
        this->active = active;
        first = NULL;
        bottom = NULL;
    }

    void push(T value) {
        if(active)
            commands.push_back(Command<T>(PUSH, value));

        if(first) {
            Node<T> *aux = first;
            first->right = new Node<T>(value);
            first = first->right;
            first->left = aux;
        } else {
            first = new Node<T>(value);
            bottom = first;
        }
    }

    T top() {
        if(active)
            commands.push_back( Command<T>(TOP) );

        if(first)
            return first->value;
        return 0;
    }

    T pop() {
        if(active)
            commands.push_back( Command<T>( PUSH, top() ) );

        if(first) {
            T value = top();
            Node<T> *aux = first;
            first = first->left;
            delete aux;
            return value;
        }
        return 0;
    }

    bool rollback() {
        if(!active)
            return false;
        
        if(!commands.empty()) {
            Command<T> command = commands.back();
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

    bool commit(Block *topBlock) {
        if( topBlock->getTop() ) {
            first->right = topBlock->getBottom();
            first = topBlock->getTop();
            return true;
        }
        return false;
    }

    bool getActive() {
        return active;
    }

    Node<T> *getBottom() {
        return bottom;
    }

    Node<T> *getTop() {
        return first;
    }

    std::string toString() {
        if(first) {
            std::stringstream ss;
            Node<T> *it = bottom;
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
};

#endif