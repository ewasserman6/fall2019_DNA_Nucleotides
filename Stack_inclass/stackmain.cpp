#include <iostream>
#include "GenStack.h"

using namespace std;


int main(int argc, char **argv){
    GenStack myStack(10);

    myStack.push('E');
    myStack.push('r');
    myStack.push('i');
    myStack.push('c');

    cout << "Popping: " << myStack.pop() << endl;
    cout << "Peek: " << myStack.peek() << endl;

    myStack.push('F');
    cout << "Peek: " << myStack.peek() << endl;

    while(!myStack.isEmpty()){
        cout << "Popping: " << myStack.pop() << endl;

    }

    cout << "Is the stack empty? " << myStack.isEmpty() << endl;
    return 0;
}
