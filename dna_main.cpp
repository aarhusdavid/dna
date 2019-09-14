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

    // tells user that program was completed
    cout << "progam exited successfully" << endl;

    //closes file
    outputFile.close();

    return 0;
}
