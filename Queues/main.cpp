#include <iostream>
#include "GenQueue.h"

using namespace std;

int main(){
    GenQueue* myQ = new GenQueue(10);

    myQ->insert('e'); // use arrow when invoking the method on a pointer or something like that
    myQ->insert('r');
    myQ->insert('i');
    myQ->insert('c');

    while(!myQ->isEmpty()){
        char c = myQ->remove();
        cout << c << endl;
    }
    delete myQ;
    return 0;
}
