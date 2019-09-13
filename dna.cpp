#include "dna.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>



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

double dna::mean(string input)
{

    int a_count = 0;
    int c_count = 0;
    int t_count = 0;
    int g_count = 0;
    double count = 0;
    int error = 0;
    double strandCount = 0;

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







double dna::variance(string input)
{
    double count = 0.0;
    int error = 0;
    double strandCount = 0.0;
    double av = mean(input);
    double var_total = 0.0;
    double var = 0.0;
    double s_var = 0.0;


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
                count++;}
            else if (charr =='c'){
                count++;}
            else if (charr =='t'){
                count++;}
            else if (charr =='g'){
                count++;}
            else
                count++;
        }
        var = count - av;
        s_var = pow(var,2);
        var_total = var_total + s_var;
        count = 0;
        var = 0;
        s_var = 0;
    }
    double new_var = var_total / (strandCount-1);
    return new_var;
    infile.close();
}
