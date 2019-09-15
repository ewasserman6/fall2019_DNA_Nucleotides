/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 1: DNA

I created this class for my implementation */

#include "assignment1DNA.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// constructor function
assignment1DNA::assignment1DNA()
{

};
//destructor function
assignment1DNA::~assignment1DNA()
{
    cout << "Object has been deleted" << endl;
};

//this function variance takes in fileName, mean, and the linecount. It finds the length of each line subtracts the mean, and squares that value.
float assignment1DNA::variance(string fileName, float mean, float lineCount)
{
    ifstream inFile;
    string dna;
    inFile.open(fileName); // open file

    float addNum = 0;

    while(getline(inFile, dna, '\n')){

        addNum += pow(dna.size() - mean, 2.0);// (line length - mean)^2

    }

    inFile.close();
    return addNum/lineCount;


}

// Standard deviation is simply the square root of variance so I passed in
// the variance and sqrt using the math library.
float assignment1DNA::standdev(float variance)
{
    return sqrt(variance);
}

/* I passed in the string of nucleatides, individual nucelotides, and the sum. For the length of the entire
string I checked if that nucleotide == the individual nucleotide. If they did I added to nucCount.
I returned that count/ the total length of string */
float assignment1DNA::probability(string dna, char nucleotide, float sum)
{
    int nucCount = 0;

    for (int i = 0; i < dna.length(); ++i) {
        if (dna[i] == nucleotide) {
            nucCount++;
        }
    }
    return nucCount/sum;

}
/* For the probabilities, I passed in the string of nucelotides, the individual nucleotiudes, and the
sum of the string. I iteratated through one less than the length to account for the list being an odd number.
I checked if the [0] index was equal to the [1] index, if so I added to nucCount. */
float assignment1DNA::bigramProbability(string dna, string nucleotide, float sum) {
    int nucCount = 0;

    char first = nucleotide[0];
    char second = nucleotide[1];

    for (int i = 0; i < dna.length() - 1; ++i) {
        if (dna[i] == first && dna[i + 1] == second) {
            nucCount++;
        }
    }

    return nucCount/sum;
}

/* I pass in the probabilities for the individual nucleotides, the stdv, and the mean.
I then opened a file to write into. In the loop 1000, I do my gaussian calculations provided.
I then randomly generate a number 0-3, correlating to A,C,T, and G so I can randomly order
how the nucleotides are printed. I then printed the nucelotides. If the results of the gaussiian
equation were less than .5 I rounded it to one so I wouldn't skip lines  */
string assignment1DNA::random(float standdev, float mean, float probabilityA, float probabilityC, float probabilityT, float probabilityG){

    int freq_a = static_cast<int>((probabilityA * mean * 1000) + .5);
    int freq_c = static_cast<int>((probabilityC * mean * 1000) + .5);
    int freq_T = static_cast<int>((probabilityT * mean * 1000) + .5);
    int freq_g = static_cast<int>((probabilityG * mean * 1000) + .5);

    cout << freq_a << endl;
    cout << freq_c << endl;
    cout << freq_T << endl;
    cout << freq_g << endl;

    int count_a = 0;
    int count_c = 0;
    int count_g = 0;
    int count_T = 0;

    ofstream outFile;
    outFile.open("EricWasserman.out.txt", ios_base::app);
    if (outFile.is_open()){
        outFile << "Here are the appended DNA strings: " << "\n";
        outFile << "\n";

        for(int i = 0; i < 790; ++i){
            double rand_a = (double) rand()/(RAND_MAX + 1.0);
            double rand_b = (double) rand()/(RAND_MAX + 1.0);
            double pi = 3.1415926535;

            float equation_c = sqrt(-2*log(rand_a)) * cos(2*pi*rand_b * pi/180);

            float equation_d = (standdev * equation_c) + mean;

            int lineLength;

            if (equation_d <= .5) {
                lineLength = 1;
            }
            else {
                lineLength = static_cast<int>(equation_d + .5);
            }

            string line = "";
            int num_nucs = 0;

            while (num_nucs < lineLength) {

                int rand_num = rand()%4; // generate random between 1 and 4

                if (rand_num == 0) {
                    if (count_a < freq_a) {
                        line += "A";
                        num_nucs++;
                        count_a++;
                    }
                }
                else if (rand_num == 1) {
                    if (count_c < freq_c) {
                        line += "C";
                        num_nucs++;
                        count_c++;
                    }
                }
                else if (rand_num == 2) {
                    if (count_T < freq_T) {
                        line += "T";
                        num_nucs++;
                        count_T++;
                    }
                }
                else {
                    if (count_g < freq_g) {
                        line += "G";
                        num_nucs++;
                        count_g++;
                    }
                }
            }
            /*
            cout << "Count G" << count_g << "  " << freq_g << endl;
            cout << "Count T"  << count_T << "  "<< freq_T << endl;
            cout << "Count A" << count_a << "  " << freq_a << endl;
            cout << "Count C" << count_c << "  " << freq_c << endl;
            cout << i << endl;*/
            outFile << line << endl;

        }
        //outFile.close();
}

    outFile.close();
    return "DNA Strings ^^^^^ ";
};
