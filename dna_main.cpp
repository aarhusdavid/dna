//header file that declares all the files
#include "dna.h"
//allows for reading and writing files
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>


//allows you to print
using namespace std;

int main(int argc, char** argv) //argc stands for command line arguments
//argv number arguments in command line
{
    //creates file to write out to
    ofstream outputFile;
    outputFile.open("davidaarhus.txt");

    //stores command line argument; acts as scanner class from java
    string file_name = argv[1];

    //stored in the stack
    dna d;

    //writes out all the calculations to a new file
    outputFile << "David Aarhus\n2291228\nCPSC 350-01\n\n";
    outputFile << "Sum of DNA nucleotides: " << d.sumLength(file_name) << endl;
    outputFile << "Average amount of nucleotides in each DNA strand: " << d.mean(file_name) << endl;
    outputFile << "Variance: " << d.variance(file_name) << endl;
    outputFile << "Standard Deviation: " << d.stdv(file_name) << endl;
    outputFile << d.probability(file_name) << endl;

    //declares new string for appended strings
    string line;
    //iterates through 1000 strings and writes them to a file
    for(int i = 0; i < 1000; ++i)
    {
        //calc string length with mean and stdv
        int stringlength = d.gaussin(d.mean(file_name),d.variance(file_name));
        //adds new string to line
        while(stringlength != 0)
        {
            for(int i = 0; i < stringlength; ++i)
            {
                string newchar = d.getNucleo();
                line += newchar;
                stringlength--;
            }
        }
        line += "\n";
    }
    //writes through
    outputFile << line << endl;

    // tells user that program was completed
    cout << "progam exited successfully" << endl;

    //closes file
    outputFile.close();

    return 0;
}
