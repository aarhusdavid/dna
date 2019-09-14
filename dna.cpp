//header file that declares all the files
#include "dna.h"
//allows for reading and writing files
#include <iostream>
#include <fstream>
//allows calculations
#include <string>
#include <cmath>
#define _USE_MATH_DEFINES

//allows you to print
using namespace std;

//initializes count variables for each combinations
double count = 0;
double prob_count = 0;

double a_count = 0;
double aa_count = 0;
double ac_count = 0;
double at_count = 0;
double ag_count = 0;

double c_count = 0;
double ca_count = 0;
double cc_count = 0;
double ct_count = 0;
double cg_count = 0;

double t_count = 0;
double ta_count = 0;
double tc_count = 0;
double tt_count = 0;
double tg_count = 0;

double g_count = 0;
double ga_count = 0;
double gc_count = 0;
double gt_count = 0;
double gg_count = 0;

//calculates each percentage for each probability
double a_prob = 0;
double aa_prob = 0;
double ac_prob = 0;
double at_prob = 0;
double ag_prob = 0;

double c_prob = 0;
double ca_prob = 0;
double cc_prob = 0;
double ct_prob = 0;
double cg_prob = 0;

double t_prob = 0;
double ta_prob = 0;
double tc_prob = 0;
double tt_prob = 0;
double tg_prob = 0;

double g_prob = 0;
double ga_prob = 0;
double gc_prob = 0;
double gt_prob = 0;
double gg_prob = 0;


//constructor
dna::dna()
{

}

//destructor
dna::~dna()
{
    cout << "object deleted" << endl;
}

//calculates the sum of nucleotides
int dna::sumLength(string input)
{
    //variables for all the nucleotide counts, total count, error, and line count
    // int a_count = 0;
    // int c_count = 0;
    // int t_count = 0;
    // int g_count = 0;
    int error = 0;
    int strandCount = 0;

    string strand;
    ifstream infile;
    //enables reading file
    infile.open(input);
    //while loop that checks each line of file
    while(infile.peek() != EOF)
    {
        //increments strandCount
        strandCount++;
        getline(infile, strand);

        //forloop that counts the number of nucleoties
        for(int i = 0; i < strand.size(); ++i)
        {
            //changes character to lower case
            char charr = tolower(strand[i]);
            if(charr == 'a'){
                // a_count++;
                count++;}
            else if (charr =='c'){
                // c_count++;
                count++;}
            else if (charr =='t'){
                // t_count++;
                count++;}
            else if (charr =='g'){
                // g_count++;
                count++;}
            else
                ++error;
        }
    }
    //returns total count of nucleoties
    return count;
    //closes file
    infile.close();
}

//calculates mean of input file
double dna::mean(string input)
{
    //initializes variables for nucleotide counts, errors, and strandCounts
    double av_count = 0;
    int error = 0;
    double strandCount = 0;

    string strand;
    ifstream infile;
    //opens input file
    infile.open(input);
    //loops through each line of the file
    while(infile.peek() != EOF)
    {
        //increments strandcount
        strandCount++;
        //gets strand from the the file line
        getline(infile, strand);
        //iterates through and counts total nucleotides
        for(int i = 0; i < strand.size(); ++i)
        {
            //changes character to lowercase
            char charr = tolower(strand[i]);
            if(charr == 'a'){
                // a_count++;
                av_count++;}
            else if (charr =='c'){
                // c_count++;
                av_count++;}
            else if (charr =='t'){
                // t_count++;
                av_count++;}
            else if (charr =='g'){
                // g_count++;
                av_count++;}
            else
                ++error;
        }
    }
    //calculates mean by dividing total count by amount of lines
    return av_count/strandCount;
    //closes file
    infile.close();
}

//calculates variance for data set
double dna::variance(string input)
{
    //initializes variables
    double var_count = 0.0;
    int error = 0;
    double strandCount = 0.0;
    double av = mean(input);
    double var_total = 0.0;
    double var = 0.0;
    double s_var = 0.0;


    string strand;
    //reads files
    ifstream infile;
    infile.open(input);
    //iterates through file line by line
    while(infile.peek() != EOF)
    {
        strandCount++;
        //gets line from file
        getline(infile, strand);
        //iterates through strand
        for(int i = 0; i < strand.size(); ++i)
        {
            char charr = tolower(strand[i]);
            if(charr == 'a'){
                var_count++;}
            else if (charr =='c'){
                var_count++;}
            else if (charr =='t'){
                var_count++;}
            else if (charr =='g'){
                var_count++;}
            else
                var_count++;
        }

        //calculates variance
        var = var_count - av;
        s_var = pow(var,2);
        var_total = var_total + s_var;

        //sets variance variables back to 0
        var_count = 0;
        var = 0;
        s_var = 0;
    }

    //more variance calculations
    double new_var = var_total / (strandCount-1);

    //returns stdv and variance
    return new_var;
    infile.close();
}


//calculates stdv for data set
double dna::stdv(string input)
{
    //initializes variables
    double stdv_count = 0.0;
    int error = 0;
    double strandCount = 0.0;
    double av = mean(input);
    double var_total = 0.0;
    double var = 0.0;
    double s_var = 0.0;


    string strand;
    //reads files
    ifstream infile;
    infile.open(input);
    //iterates through file line by line
    while(infile.peek() != EOF)
    {
        strandCount++;
        //gets line from file
        getline(infile, strand);
        //iterates through strand
        for(int i = 0; i < strand.size(); ++i)
        {
            char charr = tolower(strand[i]);
            if(charr == 'a'){
                stdv_count++;}
            else if (charr =='c'){
                stdv_count++;}
            else if (charr =='t'){
                stdv_count++;}
            else if (charr =='g'){
                stdv_count++;}
            else
                stdv_count++;
        }

        //calculates variance
        var = stdv_count - av;
        s_var = pow(var,2);
        var_total = var_total + s_var;

        //sets variance variables back to 0
        stdv_count = 0;
        var = 0;
        s_var = 0;
    }
    double new_var = var_total / (strandCount-1);
    double stdvation = sqrt(new_var);
    return stdvation;
    infile.close();

}


//calculates probability for nucleotides
string dna::probability(string input)
{
    double error = 0;
    double strandCount = 0;

    string strand;
    ifstream infile;
    //reads file
    infile.open(input);
    //iterates through each line
    while(infile.peek() != EOF)
    {
        strandCount++;
        getline(infile, strand);
        //iterate through each strand
        for(int i = 0; i < strand.size(); i+=2)
        {
            char charr = tolower(strand[i]);
            char nextcharr = tolower(strand[i+1]);
            //counts each nucleotide combination
            if(charr == 'a'){
                a_count++;
                prob_count++;
                if (nextcharr == 'a'){
                    aa_count++;
                    a_count++;
                    prob_count++;
                }
                else if (nextcharr == 'c'){
                    ac_count++;
                    c_count++;
                    prob_count++;
                }
                else if (nextcharr == 't'){
                    at_count++;
                    t_count++;
                    prob_count++;
                }
                else if (nextcharr == 'g'){
                    ag_count++;
                    g_count++;
                    prob_count++;
                }
            }
            else if (charr =='c'){
                c_count++;
                prob_count++;
                if (nextcharr == 'a'){
                    ca_count++;
                    a_count++;
                    prob_count++;
                }
                else if (nextcharr == 'c'){
                    cc_count++;
                    c_count++;
                    prob_count++;
                }
                else if (nextcharr == 't'){
                    ct_count++;
                    t_count++;
                    prob_count++;
                }
                else if (nextcharr == 'g'){
                    cg_count++;
                    g_count++;
                    prob_count++;
                }
            }
            else if (charr =='t'){
                t_count++;
                prob_count++;
                if (nextcharr == 'a'){
                    ta_count++;
                    a_count++;
                    prob_count++;
                }
                else if (nextcharr == 'c'){
                    tc_count++;
                    c_count++;
                    prob_count++;
                }
                else if (nextcharr == 't'){
                    tt_count++;
                    t_count++;
                    prob_count++;
                }
                else if (nextcharr == 'g'){
                    tg_count++;
                    g_count++;
                    prob_count++;
                }
            }
            else if (charr =='g'){
                g_count++;
                prob_count++;
                if (nextcharr == 'a'){
                    ga_count++;
                    a_count++;
                    prob_count++;
                }
                else if (nextcharr == 'c'){
                    gc_count++;
                    c_count++;
                    prob_count++;
                }
                else if (nextcharr == 't'){
                    gt_count++;
                    t_count++;
                    prob_count++;
                }
                else if (nextcharr == 'g'){
                    gg_count++;
                    g_count++;
                    prob_count++;
                }
            }
            else
                ++error;
        }


    }

    //calculates probabilitys
    a_prob = (a_count/prob_count);
    aa_prob = (aa_count/prob_count)*100;
    ac_prob = (ac_count/prob_count)*100;
    at_prob = (at_count/prob_count)*100;
    ag_prob = (ag_count/prob_count)*100;

    c_prob = (c_count/prob_count);
    ca_prob = (ca_count/prob_count)*100;
    cc_prob = (cc_count/prob_count)*100;
    ct_prob = (ct_count/prob_count)*100;
    cg_prob = (cg_count/prob_count)*100;

    t_prob = (t_count/prob_count);
    ta_prob = (ta_count/prob_count)*100;
    tc_prob = (tc_count/prob_count)*100;
    tt_prob = (tt_count/prob_count)*100;
    tg_prob = (tg_count/prob_count)*100;

    g_prob = (g_count/prob_count);
    ga_prob = (ga_count/prob_count)*100;
    gc_prob = (gc_count/prob_count)*100;
    gt_prob = (gt_count/prob_count)*100;
    gg_prob = (gg_count/prob_count)*100;

    string sa_prob = to_string(a_prob);
    string saa_prob = to_string(aa_prob);
    string sac_prob = to_string(ac_prob);
    string sat_prob = to_string(at_prob);
    string sag_prob = to_string(ag_prob);

    string sc_prob = to_string(c_prob);
    string sca_prob = to_string(ca_prob);
    string scc_prob = to_string(cc_prob);
    string sct_prob = to_string(ct_prob);
    string scg_prob = to_string(cg_prob);

    string st_prob = to_string(t_prob);
    string sta_prob = to_string(ta_prob);
    string stc_prob = to_string(tc_prob);
    string stt_prob = to_string(tt_prob);
    string stg_prob = to_string(tg_prob);

    string sg_prob = to_string(g_prob);
    string sga_prob = to_string(ga_prob);
    string sgc_prob = to_string(gc_prob);
    string sgt_prob = to_string(gt_prob);
    string sgg_prob = to_string(gg_prob);


    //returns print statements with each calculated probability
    return ("Probability of 'a': " + sa_prob +  "%\n" + "Probability of 'aa': " + saa_prob +  "%\n" + "Probability of 'ac': " + sac_prob +  "%\n" + "Probability of 'at': " + sat_prob +  "%\n" + "Probability of 'ag': " + sag_prob +  "%\n" +   "Probability of 'c': " + sc_prob + "%\n" +  "Probability of 'ca': " + sca_prob +  "%\n" + "Probability of 'cc': " + scc_prob +  "%\n" + "Probability of 'ct': " + sct_prob +  "%\n" + "Probability of 'cg': " + scg_prob +  "%\n"  "Probability of 't': " + st_prob + "%\n" +  "Probability of 'ta': " + sta_prob +  "%\n" + "Probability of 'tc': " + stc_prob +  "%\n" + "Probability of 'tt': " + stt_prob +  "%\n" + "Probability of 'tg': " + stg_prob +  "%\n"  "Probability of 'g': " + sg_prob + "%\n" +  "Probability of 'ga': " + sga_prob +  "%\n" + "Probability of 'gc': " + sgc_prob +  "%\n" + "Probability of 'gt': " + sgt_prob +  "%\n" + "Probability of 'gg': " + sgg_prob +  "%\n" );
    infile.close();
}

string dna::getNucleo()
{
    while(true)
    {
        //num between 1 and 0
        double num = ((double) rand() / (RAND_MAX));

        //if statements that calc the probability of ACTG
        if(num <= (a_prob))
        {
            return "a";
            num = ((double) rand() / (RAND_MAX));
        }

        if(num <= (c_prob))
        {
            return "c";
            num = ((double) rand() / (RAND_MAX));
        }

        if(num <= (t_prob))
        {
            return "t";
            num = ((double) rand() / (RAND_MAX));
        }

        if(num <= (g_prob))
        {
            return "g";
            num = ((double) rand() / (RAND_MAX));
        }

    }
}

int dna::gaussin(double mean, double variance)
{
    //calculates random num for a and b (0-1)
    double a = ((double) rand() / (RAND_MAX));
    double b = ((double) rand() / (RAND_MAX));

    b = cos(2 * M_PI * b);

    //makes b positive if it is negative
    if (b < 0)
    {
        b = (b * -1);
    }

    double c = sqrt((-2) * log(a)) * b;
    // calculates random length
    double d = (variance * c) + mean;
    //turns length into int
    int round = ceil(d);

    return round;
}
