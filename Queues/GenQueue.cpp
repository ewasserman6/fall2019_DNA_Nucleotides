#include <iostream>
#include "GenQueue.h"

using namespace std;

GenQueue::GenQueue(int maxSize){
    myQueue = new char[maxSize];
    maximumSize = maxSize;
    numElements = 0;
    head = 0;
    tail = -1;
}

GenQueue::~GenQueue(){
    delete myQueue;
}

void GenQueue::insert(char data){
    if(isFull()){
        char* newArray = new char[2*maximumSize];
        for(int i = 0; i < maximumSize; ++i){
            newArray[i] = myQueue[i];
        }
        maximumSize *= 2;
        delete myQueue;
        myQueue = newArray;
    }
    myQueue[++tail] = data;
    ++numElements;
}

char GenQueue::remove(){
    char c = myQueue[head++];
    --numElements;
    return c;
}

char GenQueue::peek(){
    return myQueue[head];
}

bool GenQueue::isFull(){
    return (numElements == maximumSize);
}

bool GenQueue::isEmpty(){
    return(numElements == 0);
}

int GenQueue::getSize(){
    return numElements;
}
