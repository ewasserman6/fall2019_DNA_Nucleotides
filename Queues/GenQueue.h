//#ifndef GENQUEUE_H
//#define GENQUEUE_H

#include <iostream>

// queue of chars
class GenQueue{
public:
    GenQueue(int maxSize);
    ~GenQueue();
    void insert(char data);
    char remove();
    char peek();
    bool isFull();
    bool isEmpty();
    int getSize();

private:
    int head;
    int tail;
    int maximumSize;
    int numElements;
    char* myQueue;

};
