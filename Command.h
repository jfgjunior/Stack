#ifndef COMMAND_H
#define COMMAND_H

typedef struct Command {
    int command;
    int value;

    Command(int cmd) {
        command = cmd;
    }

    Command(int cmd, int val) {
        command = cmd;
        value = val;
    }

} Command;

#endif