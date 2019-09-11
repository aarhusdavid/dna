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
    infile.open(input);
    while (infile.peek() != EOF)
    {
        getline(infile,nextLine); // Saves the line in STRING.
        lines = lines + "\n" + nextLine;
    }
    lines = lines + "\n---------------";
    return lines;
    infile.close();

}

int dna::sumLength(string input)
{

    int a_count = 0;
    int c_count = 0;
    int t_count = 0;
    int g_count = 0;
    int count = 0;
    int error = 0;
    int strandCount = 0;

    string strand;
    ifstream infile;
    infile.open(input);
    while(infile.peek() != EOF)
    {
        strandCount++;
        getline(infile, strand);
        for(int i = 0; i < strand.size(); ++i)
        {
            char charr = tolower(strand[i]);
            if(charr == 'a'){
                a_count++;
                count++;}
            else if (charr =='c'){
                c_count++;
                count++;}
            else if (charr =='t'){
                t_count++;
                count++;}
            else if (charr =='g'){
                g_count++;
                count++;}
            else
                ++error;
        }
    }
    return count;
    infile.close();
}

int dna::mean(string input)
{

    int a_count = 0;
    int c_count = 0;
    int t_count = 0;
    int g_count = 0;
    int count = 0;
    int error = 0;
    int strandCount = 0;

    string strand;
    ifstream infile;
    infile.open(input);
    while(infile.peek() != EOF)
    {
        strandCount++;
        getline(infile, strand);
        for(int i = 0; i < strand.size(); ++i)
        {
            char charr = tolower(strand[i]);
            if(charr == 'a'){
                a_count++;
                count++;}
            else if (charr =='c'){
                c_count++;
                count++;}
            else if (charr =='t'){
                t_count++;
                count++;}
            else if (charr =='g'){
                g_count++;
                count++;}
            else
                ++error;
        }
    }
    return count/strandCount;
    infile.close();
}
