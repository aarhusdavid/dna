#include "dna.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

dna::dna()
{

}
dna::~dna()
{
    cout << "object deleted" << endl;
}

string dna::countLength(string input)
{
    string STRING;
    ifstream infile;
    infile.open (input);
    getline(infile,STRING); // Saves the line in STRING.
    return STRING;
    infile.close();

    // int count = 0;
    // for(int i = 0; i < input.size(); ++i)
    // {
    //     char strInput = tolower(input[i]);
    //     if(strInput == 'a')
    //         count++;
    //     else if (strInput =='e')
    //         count++;
    //     else if (strInput =='i')
    //         count++;
    //     else if (strInput =='o')
    //         count++;
    //     else if (strInput =='u')
    //         count++;
    // }
    // return count;
}











// http://www.cplusplus.com/doc/tutorial/files/
