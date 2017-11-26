#ifndef BLOCK_H
#define BLOCK_H

#include "Node.h"
#include "Command.h"
#include <vector>
#include "Common.h"
#include "sstream"

class Block {
private:
    Node *first;
    Node *bottom;
    std::vector<Command> commands;
    bool active;
public:
    Block(bool);
    int top();
    void push(int);
    int pop();

    bool rollback();
    bool commit(Block*);

    bool getActive();
    Node* getBottom();
    Node* getTop();

    std::string toString();
};

#endif