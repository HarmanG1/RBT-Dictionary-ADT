/********************************************************************************* 
* Harman Gidha
* Order.cpp
*********************************************************************************/ 

#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>
#include"Dictionary.h"

using namespace std;

int main(int argc, char * argv[])
{
    // check command line for correct number of arguments
    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return(EXIT_FAILURE);
    }

    ifstream in; 
    ofstream out;
    // open files for reading and writing 
    in.open(argv[1]);
    if( !in.is_open() ){
        cerr << "Unable to open file " << argv[1] << " for reading" << endl;
        return(EXIT_FAILURE);
    }

    out.open(argv[2]);
    if( !out.is_open() ){
        cerr << "Unable to open file " << argv[2] << " for writing" << endl;
        return(EXIT_FAILURE);
    }

    int linec = 0;
    string word;
    Dictionary D = Dictionary();
    while(in >> word)
    {
        linec++;
        D.setValue(word, linec);
    }
    out << D << endl;
    out << D.pre_string() << endl;

    // close files 
    in.close();
    out.close();

    return(EXIT_SUCCESS);
}