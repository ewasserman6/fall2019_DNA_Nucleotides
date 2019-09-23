#include <iostream>
#include "GenStack.h"

using namespace std;

GenStack::GenStack(){
    myArray = new char[128];
    size = 128;
    top = -1;
}

GenStack::GenStack(int maxSize){
    myArray = new char[maxSize];
    size = maxSize;
    top = -1;
}

GenStack::~GenStack(){
    // do some research
    // figure out what this does - only one line
    //delete[myArray]; // something like this
}

void GenStack::push(char d){ // make sure theres room for it
    // error checking, make sure its not empty
    myArray[++top] = d; // iterating to 0 - first element of the array. pre increment becuase it increments to 0 before evaluating -1.
}

char GenStack::pop(){ // returns and removes
    // error checking - make sure its not empty
    return myArray[top--];
}

char GenStack::peek(){ // returns but doesn NOT remove
    // check if empty
    return myArray[top];
}

bool GenStack::isFull(){
    return (top == size - 1); // returns true or false - Full - true
}

bool GenStack::isEmpty(){ // true - empty, false - full
    return (top == - 1);
}
