#include <iostream>
#include "Stack.h"

using namespace std;

void printMenu();

int main() {
    int option;
    Stack stack;
    while( option != 7 ){
        printMenu();
        cin >> option;
        switch (option) {
            case PUSH:
                int value;
                cout << "Type de value: " << endl;
                cin.clear();
                cin >> value;
                cout << "Value " << value << endl;
                stack.push(value);
                cout << "Push: " << stack.top() << endl;
                break;
            case TOP:
                cout << "Top: " << stack.top() << endl;
                break;
            case POP:
                cout << "Pop: " << stack.pop() << endl;
                break;
            case BEGIN:
                cout << "Stargin new block" << endl;
                stack.begin();
                break;
            case ROLLBACK:
                cout << "Undo last change" << endl;
                stack.rollback();
                break;
            case COMMIT:
                cout << "Mergin blocks" << endl; 
                stack.commit();
                break;
            case PRINT_BLOCK:
                cout << stack.toString() << endl;
                break;
            case EXIT:
                break;
        }
    }
    
}

void printMenu() {
    cout << "Choose an option:" << endl;
    cout << "0 - PUSH" << endl << "1 - TOP" << endl << "2 - POP"
         << endl << "3 - BEGIN" << endl << "4 - ROLLBACK" << endl
         << "5 - COMMIT" << endl << "6 - PRINT BLOCK" << endl
         << "7 - EXIT" << endl;
}