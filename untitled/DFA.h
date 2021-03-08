//
// Created by chris on 3/7/2021.
//

#ifndef UNTITLED_DFA_H
#define UNTITLED_DFA_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

class DFA {


public:

    DFA();

    //encodes a string into it's state number
    int encode(std::string s);

    //determines if a string is in the language or not
    bool isValid(std::string s);

    //a window of 5 + 1
    int window(std::string buffer, char c);

    //determines if the buffer + the next chars are valid or not
    void determiner (std::string buffer);

    //creates all the states in the DFA

    //count all valid numbers for n
    int count(int n);

private:

    const int SIZE = 1365;
    std::vector<int> previous;
    std::vector<int> current;


    std::vector<std::string> myDFA;

};


#endif //UNTITLED_DFA_H
