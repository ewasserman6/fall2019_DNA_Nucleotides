#include "Quiz1.h"
#include <iostream>

using namespace std;

int main1(int argc, char** argv)
{
    if(argc > 1)
    {
        //string test = argv[1];
        string test = "";

        cout << "please enter a string" << endl;
        cin >> test;

        Quiz1 q;

        cout << "number of command line arguments: " << argc << endl;
        cout << "the number of vowels in " << test << " is: " << q.countVowels(test) << endl;
    }
    else
    {
        cout << "please provide an input string" << endl;
        cout << "USAGE: bskjdcnjkd" << endl;
    }



    cout << "program exited successfully" << endl;

    return 0;

}
