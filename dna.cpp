//header file that declares all the files
#include "dna.h"
//allows for reading and writing files
#include <iostream>
#include <fstream>
//allows calculations
#include <string>
#include <cmath>

//allows you to print
using namespace std;

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
    int a_count = 0;
    int c_count = 0;
    int t_count = 0;
    int g_count = 0;
    int count = 0;
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
    //returns total count of nucleoties
    return count;
    //closes file
    infile.close();
}

//calculates mean of input file
double dna::mean(string input)
{
    //initializes variables for nucleotide counts, errors, and strandCounts
    int a_count = 0;
    int c_count = 0;
    int t_count = 0;
    int g_count = 0;
    double count = 0;
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
    //calculates mean by dividing total count by amount of lines
    return count/strandCount;
    //closes file
    infile.close();
}

//calculates variance for data set
double dna::variance(string input)
{
    //initializes variables
    double count = 0.0;
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

        //calculates variance
        var = count - av;
        s_var = pow(var,2);
        var_total = var_total + s_var;

        //sets variance variables back to 0
        count = 0;
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
    double count = 0.0;
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

        //calculates variance
        var = count - av;
        s_var = pow(var,2);
        var_total = var_total + s_var;

        //sets variance variables back to 0
        count = 0;
        var = 0;
        s_var = 0;
    }
    double square_var_total = pow(var_total,2);
    double stdvation = square_var_total / (strandCount - 1);

    return stdvation;
    infile.close();

}


//calculates probability for nucleotides
string dna::probability(string input)
{
    //initializes count variables for each combinations
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

    double count = 0;
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
                count++;
                if (nextcharr == 'a'){
                    aa_count++;
                    a_count++;
                    count++;
                }
                else if (nextcharr == 'c'){
                    ac_count++;
                    c_count++;
                    count++;
                }
                else if (nextcharr == 't'){
                    at_count++;
                    t_count++;
                    count++;
                }
                else if (nextcharr == 'g'){
                    ag_count++;
                    g_count++;
                    count++;
                }
            }
            else if (charr =='c'){
                c_count++;
                count++;
                if (nextcharr == 'a'){
                    ca_count++;
                    a_count++;
                    count++;
                }
                else if (nextcharr == 'c'){
                    cc_count++;
                    c_count++;
                    count++;
                }
                else if (nextcharr == 't'){
                    ct_count++;
                    t_count++;
                    count++;
                }
                else if (nextcharr == 'g'){
                    cg_count++;
                    g_count++;
                    count++;
                }
            }
            else if (charr =='t'){
                t_count++;
                count++;
                if (nextcharr == 'a'){
                    ta_count++;
                    a_count++;
                    count++;
                }
                else if (nextcharr == 'c'){
                    tc_count++;
                    c_count++;
                    count++;
                }
                else if (nextcharr == 't'){
                    tt_count++;
                    t_count++;
                    count++;
                }
                else if (nextcharr == 'g'){
                    tg_count++;
                    g_count++;
                    count++;
                }
            }
            else if (charr =='g'){
                g_count++;
                count++;
                if (nextcharr == 'a'){
                    ga_count++;
                    a_count++;
                    count++;
                }
                else if (nextcharr == 'c'){
                    gc_count++;
                    c_count++;
                    count++;
                }
                else if (nextcharr == 't'){
                    gt_count++;
                    t_count++;
                    count++;
                }
                else if (nextcharr == 'g'){
                    gg_count++;
                    g_count++;
                    count++;
                }
            }
            else
                ++error;
        }
    }

    //calculates each percentage for each probability
    double a_prob = (a_count/count)*100;
    double aa_prob = (aa_count/count)*200;
    double ac_prob = (ac_count/count)*200;
    double at_prob = (at_count/count)*200;
    double ag_prob = (ag_count/count)*200;

    double c_prob = (c_count/count)*100;
    double ca_prob = (ca_count/count)*200;
    double cc_prob = (cc_count/count)*200;
    double ct_prob = (ct_count/count)*200;
    double cg_prob = (cg_count/count)*200;

    double t_prob = (t_count/count)*100;
    double ta_prob = (ta_count/count)*200;
    double tc_prob = (tc_count/count)*200;
    double tt_prob = (tt_count/count)*200;
    double tg_prob = (tg_count/count)*200;

    double g_prob = (g_count/count)*100;
    double ga_prob = (ga_count/count)*200;
    double gc_prob = (gc_count/count)*200;
    double gt_prob = (gt_count/count)*200;
    double gg_prob = (gg_count/count)*200;

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
