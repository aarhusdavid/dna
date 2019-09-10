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
    string nextLine;
    string lines;
    ifstream infile;
    infile.open (input);
    while (infile.peek() != EOF)
    {
        getline(infile,nextLine); // Saves the line in STRING.
        lines = lines + "\n" + nextLine;
    }
    return lines;
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
