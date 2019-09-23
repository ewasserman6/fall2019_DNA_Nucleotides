/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Game of Life

I created this class for my implementation */

#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) // main function
{
    if(argc > 1){
        string test = argv[1];
        cout << "Command line arguments: " << argc << endl;

        cout << "Would you like a map file or would you like random assignment? (M or R)" << endl;

        string options;
        cin >> options;
        if (options == "M"){
            // provide map file
            cout << "Map File" << endl;
        }
        else if(options == "R"){
            // random assignment
            cout << "Random" << endl;

            cout << "Enter the x dimesnsion of the world: " << endl;

            string xOptions;
            int xOptions;
            cin >> xOptions;

            cout << "Enter the y dimesnsion of the world: " << endl;

            string yOptions;
            int yOptions;
            cin >> yOptions;

            gameBoard[xOptions][yOptions];

            gameBoard[0][0] = 1;

            cout << gameBoard << endl;

        }
        else{
            cout << "Not a command" << endl;
        }
}
