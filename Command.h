#ifndef COMMAND_H
#define COMMAND_H

template <class T>
struct Command {
    int command;
    T value;

    Command(int cmd) {
        command = cmd;
    }

    Command(int cmd, T val) {
        command = cmd;
        value = val;
    }
};

#endif