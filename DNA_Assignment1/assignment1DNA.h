/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 1: DNA

My header class for my assignment1DNA.cpp */

#include <iostream>
#include <string>


using namespace std;

class assignment1DNA // declaring class
{
public: // access modifier
    assignment1DNA(); // constructor
    ~assignment1DNA(); // destructor
    float sum(string input);
    float mean(string input);
    float variance(string fileName, float mean, float lineCount);
    float standdev(float variance);
    float probability(string input, char nucleotide, float sum);
    float bigramProbability(string dna, string nucleotide, float sum);
    string random(float standdev, float mean, float probabilityA, float probabilityT, float probabilityC, float probabilityG);
};
