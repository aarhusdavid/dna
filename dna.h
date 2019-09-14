#include <iostream> //preprocessor directive

using namespace std; //allows you to print

class dna
{
public:
    dna(); //constructor
    ~dna(); //destructor
    
    //initialzes methods
    string countLength(string input);
    int sumLength(string input);
    double mean(string input);
    double variance(string input);
    double stdv(string input);
    string probability(string input);
    string getNucleo();
    int gaussin(double mean, double stdv);



};
