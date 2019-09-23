/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 1: DNA

I created this class so I could open the file only when I needed to compared to opening it
every time I called one of my functions in my main.cpp */

#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// constructor function
FileHandler::FileHandler()
{

};
//destructor function
FileHandler::~FileHandler()
{
    cout << "Object has been deleted" << endl;
};

/* lineCount calculates the number of lines in the string of nucleotides so I can calculate
the mean.  */
float FileHandler::lineCount(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    string dna;
    float lineCount = 0;

    while(true){
        inFile >> dna;
        if(inFile.eof()) break;
        lineCount++;
    }
    inFile.close();
    return lineCount;
}

/*This functions reads the dna file in. It also makes all the nucleotides upper case. */
string FileHandler::readFile(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    string dna;
    string output;
    string tempDna;

    while (true){
        inFile >> dna;
        if (inFile.eof()){
            break;
        }
        else{
            tempDna += dna;
        }

    }

    // make everything upper case
    for (int i = 0; i < tempDna.length(); ++i) {
        output += toupper(tempDna[i]);
    }

    inFile.close();
    return output;
}
