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







string dna::variance(string input)
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
    double square_var_total = pow(var_total,2);
    double stdv = square_var_total / (strandCount - 1);
    string s_new_var = to_string(new_var);
    string s_stdv = to_string(stdv);
    return (s_new_var + " and Standard Deviation is: " + s_stdv);
    infile.close();
}

string dna::probability(string input)
{
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
    infile.open(input);
    while(infile.peek() != EOF)
    {
        strandCount++;
        getline(infile, strand);
        for(int i = 0; i < strand.size(); ++i)
        {
            char charr = tolower(strand[i]);
            char nextcharr = tolower(strand[i+1]);

            if(charr == 'a'){
                a_count++;
                count++;
                if (nextcharr == 'a')
                    aa_count++;
                else if (nextcharr == 'c')
                    ac_count++;
                else if (nextcharr == 't')
                    at_count++;
                else if (nextcharr == 'g')
                    ag_count++;
            }
            else if (charr =='c'){
                c_count++;
                count++;
                if (nextcharr == 'a')
                    ca_count++;
                else if (nextcharr == 'c')
                    cc_count++;
                else if (nextcharr == 't')
                    ct_count++;
                else if (nextcharr == 'g')
                    cg_count++;
            }
            else if (charr =='t'){
                t_count++;
                count++;
                if (nextcharr == 'a')
                    ta_count++;
                else if (nextcharr == 'c')
                    tc_count++;
                else if (nextcharr == 't')
                    tt_count++;
                else if (nextcharr == 'g')
                    tg_count++;
            }
            else if (charr =='g'){
                g_count++;
                count++;
                if (nextcharr == 'a')
                    ga_count++;
                else if (nextcharr == 'c')
                    gc_count++;
                else if (nextcharr == 't')
                    gt_count++;
                else if (nextcharr == 'g')
                    gg_count++;
            }
            else
                ++error;
        }
    }

    double a_prob = (a_count/count)*100;
    double aa_prob = (aa_count/count)*50;
    double ac_prob = (ac_count/count)*50;
    double at_prob = (at_count/count)*50;
    double ag_prob = (ag_count/count)*50;

    double c_prob = (c_count/count)*100;
    double ca_prob = (ca_count/count)*50;
    double cc_prob = (cc_count/count)*50;
    double ct_prob = (ct_count/count)*50;
    double cg_prob = (cg_count/count)*50;

    double t_prob = (t_count/count)*100;
    double ta_prob = (ta_count/count)*50;
    double tc_prob = (tc_count/count)*50;
    double tt_prob = (tt_count/count)*50;
    double tg_prob = (tg_count/count)*50;

    double g_prob = (g_count/count)*100;
    double ga_prob = (ga_count/count)*50;
    double gc_prob = (gc_count/count)*50;
    double gt_prob = (gt_count/count)*50;
    double gg_prob = (gg_count/count)*50;

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


    return ("Probability of 'a': " + sa_prob +  "%\n" + "Probability of 'aa': " + saa_prob +  "%\n" + "Probability of 'ac': " + sac_prob +  "%\n" + "Probability of 'at': " + sat_prob +  "%\n" + "Probability of 'ag': " + sag_prob +  "%\n" +   "Probability of 'c': " + sc_prob + "%\n" +  "Probability of 'ca': " + sca_prob +  "%\n" + "Probability of 'cc': " + scc_prob +  "%\n" + "Probability of 'ct': " + sct_prob +  "%\n" + "Probability of 'cg': " + scg_prob +  "%\n"  "Probability of 't': " + st_prob + "%\n" +  "Probability of 'ta': " + sta_prob +  "%\n" + "Probability of 'tc': " + stc_prob +  "%\n" + "Probability of 'tt': " + stt_prob +  "%\n" + "Probability of 'tg': " + stg_prob +  "%\n"  "Probability of 'g': " + sg_prob + "%\n" +  "Probability of 'ga': " + sga_prob +  "%\n" + "Probability of 'gc': " + sgc_prob +  "%\n" + "Probability of 'gt': " + sgt_prob +  "%\n" + "Probability of 'gg': " + sgg_prob +  "%\n" );
    infile.close();
}
