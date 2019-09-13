#include "dna.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) //argc stands for command line arguments
//argv number arguments in command line
{
    // string test = argv[1];
    //this pulls the string from the command line
    string file_name = "";

    cout << "Enter file name: " << endl;
    cin >> file_name; //console input; like the scanner class in java to read input from user

    dna d; //stored in the stack

    cout << "number of command line arguments: " << argc << endl;
    cout << "Name of the file: " << file_name << endl;
    cout << "Strings in file: " << "\n---------------" << d.countLength(file_name) << endl;
    cout << "Sum of DNA nucleotides: " << d.sumLength(file_name) << endl;
    cout << "Average amount of nucleotides in each DNA strand: " << d.mean(file_name) << endl;
    cout << "Variance: " << d.variance(file_name) << endl;
    cout << d.probability(file_name) << endl;




    cout << "progam exited successfully" << endl;

    return 0;
}
