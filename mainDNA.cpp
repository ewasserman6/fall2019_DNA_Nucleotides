/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 1: DNA

My main class for my logic. */

#include "assignment1DNA.h"
#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char** argv) // main function
{
    if(argc > 1){
        string test = argv[1];
        assignment1DNA q;
        cout << "Command line arguments: " << argc << endl; // print the command line arguments
        bool inputError = true;
        while(inputError){
            cout << "Results to .txt file (EricWasserman.out.txt) " << endl; // print the file were writing to
            FileHandler fileController;
            string dnaString = fileController.readFile(test);

            float sum = dnaString.length(); // sum of nucleotudes

            float lineCount = fileController.lineCount(test); // counts line

            float mean = sum/lineCount; // mean

            float variance = q.variance(test , mean, lineCount); // variance

            float standdev = sqrt(variance); // standard deviation


            char a = 'A';
            char t = 'T';
            char c = 'C';
            char g = 'G';

            string aa = "AA";
            string ac = "AC";
            string at = "AT";
            string ag = "AG";
            string ca = "CA";
            string cc = "CC";
            string ct = "CT";
            string cg = "CG";
            string ga = "GA";
            string gc = "GC";
            string gt = "GT";
            string gg = "GG";
            string ta = "TA";
            string tc = "TC";
            string tt = "TT";
            string tg = "TG";

            // calling the probability function for each individual nucleotide ACTG
            double probA = q.probability(dnaString, a, sum);
            double probT = q.probability(dnaString, t, sum);
            double probC = q.probability(dnaString, c, sum);
            double probG = q.probability(dnaString, g, sum);

            // calling the bigramProbability function for bigram probabilities
            double probAA = q.bigramProbability(dnaString, aa, sum);
            double probAC = q.bigramProbability(dnaString, ac, sum);
            double probAT = q.bigramProbability(dnaString, at, sum);
            double probAG = q.bigramProbability(dnaString, ag, sum);
            double probCC = q.bigramProbability(dnaString, cc, sum);
            double probCA = q.bigramProbability(dnaString, ca, sum);
            double probCT = q.bigramProbability(dnaString, ct, sum);
            double probCG = q.bigramProbability(dnaString, cg, sum);
            double probTT = q.bigramProbability(dnaString, tt, sum);
            double probTA = q.bigramProbability(dnaString, ta, sum);
            double probTG = q.bigramProbability(dnaString, tg, sum);
            double probTC = q.bigramProbability(dnaString, tc, sum);
            double probGC = q.bigramProbability(dnaString, cc, sum);
            double probGA = q.bigramProbability(dnaString, ca, sum);
            double probGT = q.bigramProbability(dnaString, ct, sum);
            double probGG = q.bigramProbability(dnaString, cg, sum);

            inputError = false;

            ofstream outFile;
            outFile.open("EricWasserman.out.txt", ios_base::app); // open ouput file
            if (outFile.is_open())
            {
                // write all my info to the output file
                  outFile << "Eric Wasserman" << endl;
                  outFile << "2300841" << endl;
                  outFile << "ewasserman@chapman.edu" << endl;
                  outFile << "CPSC 350 Section 3" << endl;
                  outFile << "Assignment 1: DNA" << endl;
                  outFile << "\n";

                  outFile << "Sum: " << sum << endl;
                  outFile << "Mean: " << mean << endl;
                  outFile << "Variance: " << variance << endl;
                  outFile << "Standard Deviation: " << standdev << endl;

                  outFile << "\n";
                  outFile << "Relative probabilities for nucleotides and nucleotide bigrams: " << endl;
                  outFile << endl;

                  outFile << c << ": " <<  q.probability(dnaString, c, sum) << endl;
                  outFile << t << ": " <<  q.probability(dnaString, t, sum) << endl;
                  outFile << a << ": " <<  q.probability(dnaString, a, sum) << endl;
                  outFile << g << ": " <<  q.probability(dnaString, g, sum) << endl;
                  outFile << aa << ": " <<  q.bigramProbability(dnaString, aa, sum) << endl;
                  outFile << ac << ": " <<  q.bigramProbability(dnaString, ac, sum) << endl;
                  outFile << at << ": " <<  q.bigramProbability(dnaString, at, sum) << endl;
                  outFile<< ag << ": " <<  q.bigramProbability(dnaString, ag, sum) << endl;
                  outFile << ca << ": " <<  q.bigramProbability(dnaString, ca, sum) << endl;
                  outFile << cc << ": " <<  q.bigramProbability(dnaString, cc, sum) << endl;
                  outFile<< ct << ": " <<  q.bigramProbability(dnaString, ct, sum) << endl;
                  outFile<< cg << ": " <<  q.bigramProbability(dnaString, cg, sum) << endl;
                  outFile<< ga << ": " <<  q.bigramProbability(dnaString, ga, sum) << endl;
                  outFile<< gc << ": " <<  q.bigramProbability(dnaString, gc, sum) <<endl;
                  outFile << gt << ": " <<  q.bigramProbability(dnaString, gt, sum) << endl;
                  outFile << gg << ": " <<  q.bigramProbability(dnaString, gg, sum) << endl;
                  outFile << ta << ": " <<  q.bigramProbability(dnaString, ta, sum) << endl;
                  outFile << tc << ": " <<  q.bigramProbability(dnaString, tc, sum) << endl;
                  outFile << tt << ": " <<  q.bigramProbability(dnaString, tt, sum) << endl;
                  outFile << tg << ": " <<  q.bigramProbability(dnaString, tg, sum) << endl;
                  outFile << endl;
            }
            // error checking
            else{
                cout << "File not open" << endl;
            }
            // calling the 1000 strings
            string gaussian = q.random(standdev, mean, probA, probC, probT, probG);

            outFile.close();

            cout << "Continue? (Y or N)" << endl;

            string options;
            cin >> options;
            if (options == "N"){
                outFile.close();
                cout << "Simulation over" << endl;
                return 0;
            }
            // if the user wangts to continue prompt a file name and run another simulation
            else if(options == "Y"){
                string nextSim;
                cout << "File Name: " << endl;
                cin >> nextSim;

                float sum = dnaString.length();

                float lineCount = fileController.lineCount(nextSim);
                float mean = sum/lineCount;
                float variance = q.variance(nextSim , mean, lineCount);
                float standdev = sqrt(variance);

                double probA = q.probability(nextSim, a, sum);
                double probT = q.probability(nextSim, t, sum);
                double probC = q.probability(nextSim, c, sum);
                double probG = q.probability(nextSim, g, sum);

                double probAA = q.bigramProbability(nextSim, aa, sum);
                double probAC = q.bigramProbability(nextSim, ac, sum);
                double probAT = q.bigramProbability(nextSim, at, sum);
                double probAG = q.bigramProbability(nextSim, ag, sum);
                double probCC = q.bigramProbability(nextSim, cc, sum);
                double probCA = q.bigramProbability(nextSim, ca, sum);
                double probCT = q.bigramProbability(nextSim, ct, sum);
                double probCG = q.bigramProbability(nextSim, cg, sum);
                double probTT = q.bigramProbability(nextSim, tt, sum);
                double probTA = q.bigramProbability(nextSim, ta, sum);
                double probTG = q.bigramProbability(nextSim, tg, sum);
                double probTC = q.bigramProbability(nextSim, tc, sum);
                double probGC = q.bigramProbability(nextSim, cc, sum);
                double probGA = q.bigramProbability(nextSim, ca, sum);
                double probGT = q.bigramProbability(nextSim, ct, sum);
                double probGG = q.bigramProbability(dnaString, cg, sum);

                if (outFile.is_open())
                {
                    outFile << "Sum: " << sum << endl;
                    outFile << "Mean: " << mean << endl;
                    outFile << "Variance: " << variance << endl;
                    outFile << "Standard Deviation: " << standdev << endl;

                    outFile << "\n";
                    outFile << "Relative probabilities for nucleotides and nucleotide bigrams (SIM2): " << endl;

                    outFile << c << ": " <<  q.probability(nextSim, c, sum) << endl;
                    outFile << t << ": " <<  q.probability(nextSim, t, sum) << endl;
                    outFile << a << ": " <<  q.probability(nextSim, a, sum) << endl;
                    outFile << g << ": " <<  q.probability(nextSim, g, sum) << endl;
                    outFile << aa << ": " <<  q.bigramProbability(nextSim, aa, sum) << endl;
                    outFile << ac << ": " <<  q.bigramProbability(nextSim, ac, sum) << endl;
                    outFile << at << ": " <<  q.bigramProbability(nextSim, at, sum) << endl;
                    outFile<< ag << ": " <<  q.bigramProbability(nextSim, ag, sum) << endl;
                    outFile << ca << ": " <<  q.bigramProbability(nextSim, ca, sum) << endl;
                    outFile << cc << ": " <<  q.bigramProbability(nextSim, cc, sum) << endl;
                    outFile<< ct << ": " <<  q.bigramProbability(nextSim, ct, sum) << endl;
                    outFile<< cg << ": " <<  q.bigramProbability(nextSim, cg, sum) << endl;
                    outFile<< ga << ": " <<  q.bigramProbability(nextSim, ga, sum) << endl;
                    outFile<< gc << ": " <<  q.bigramProbability(nextSim, gc, sum) <<endl;
                    outFile << gt << ": " <<  q.bigramProbability(nextSim, gt, sum) << endl;
                    outFile << gg << ": " <<  q.bigramProbability(nextSim, gg, sum) << endl;
                    outFile << ta << ": " <<  q.bigramProbability(nextSim, ta, sum) << endl;
                    outFile << tc << ": " <<  q.bigramProbability(nextSim, tc, sum) << endl;
                    outFile << tt << ": " <<  q.bigramProbability(nextSim, tt, sum) << endl;
                    outFile << tg << ": " <<  q.bigramProbability(nextSim, tg, sum) << endl;
                    outFile << endl;
                }
                //error checking
                else{
                    cout << "File not open" << endl;
                }
                // 1000 strings for sim2
                string gaussian = q.random(standdev, mean, probA, probC, probT, probG);
            }
            //error checking
            else{
                cout << "Not a command" << endl;
            }
    }
}
    else{
        cout << "Enter parameter" << endl;
    }
};
