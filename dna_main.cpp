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
    cout << "Strings in file: " << d.countLength(file_name) << endl;
    cout << "progam exited successfully" << endl;

    return 0;
}
