/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 1: DNA

My header class for my FileHandler.cpp */
#include <iostream>
#include <string>


using namespace std;

class FileHandler// declaring class
{
public: // access modifier
    FileHandler(); // constructor
    ~FileHandler(); // destructor
    string readFile(string fileName);
    float lineCount(string fileName);
};
