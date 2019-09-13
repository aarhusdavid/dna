#include "dna.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) //argc stands for command line arguments
//argv number arguments in command line
{
    ofstream outputFile;
    outputFile.open("davidaarhus.txt");

    outputFile << argv[1];
    string file_name = argv[1];

    dna d; //stored in the stack

    outputFile << "Strings in file: " << "\n---------------" << d.countLength(file_name) << endl;
    outputFile << "Sum of DNA nucleotides: " << d.sumLength(file_name) << endl;
    outputFile << "Average amount of nucleotides in each DNA strand: " << d.mean(file_name) << endl;
    outputFile << "Variance: " << d.variance(file_name) << endl;
    outputFile << d.probability(file_name) << endl;


    cout << "progam exited successfully" << endl;
    outputFile.close();

    return 0;
}
