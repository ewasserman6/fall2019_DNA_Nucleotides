#include "Quiz1.h" // user defined file
#include <iostream> // system library

using namespace std;

Quiz1::Quiz1()
{

}
Quiz1::~Quiz1()
{
    cout << "object deleted" << endl;
}

int Quiz1::countVowels(string input)
{
    int count = 0 ;
    for(int i = 0; i < input.size(); ++i) // for loops - same as Java
    {
        char strInput = tolower(input[i]); // optional - making them all lower
        if(strInput == 'a')
            count++;
        else if(strInput == 'e')
            count++;
        else if(strInput == 'i')
            count++;
        else if(strInput == 'o')
            count++;
        else if(strInput == 'u')
            count++;
    }
    return count;
}
