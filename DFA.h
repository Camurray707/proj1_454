//
// Created by chris on 3/7/2021.
//

#ifndef UNTITLED_DFA_H
#define UNTITLED_DFA_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <gmpxx.h>

class DFA {


public:

    //creates all the states in the DFA
    DFA();

    //encodes a string into it's state number
    int encode(std::string s);

    //determines if a string is in the language or not
    bool isValid(std::string s);

    //a window of 5 + 1
    int window(std::string buffer, char c);

    //determines if the buffer + the next chars are valid or not
    void determiner (std::string buffer);


    //count all valid numbers for n
    mpz_class count(mpz_class n);

private:

    const int SIZE = 1365;

    std::vector<mpz_class> previous;
    std::vector<mpz_class> current;

    //vector of all the states and the reject state created in the constructor
    std::vector<std::string> myDFA;

};


#endif //UNTITLED_DFA_H
