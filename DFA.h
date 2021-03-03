//
// Created by chris on 2/24/21.
//

#ifndef CS_454_DFA_H
#define CS_454_DFA_H

#include <iostream>
#include <vector>
#include <tuple>
#include <gmpxx.h>
#include "State.h"

class DFA {

public:
    DFA();

    int count(int n);                                         //computes the number of strings w of length n over { a, b, c, d }.

    mpz_class minString();                                          //takes as input a DFA M and outputs a string w of shortest length accepted by the DFA.

    mpz_class smallestMultiple(int k, std::vector<int> S);          //takes as inp9ut a positive iteger k, and a subset S of {1-9} and outsputs the smallest positive integer y > 0 that is an integer multiple of k and has only the digits from S.

    void createDFA();

private:

    mpz_class currCount;
    std::vector<State> myStates;


};


#endif //CS_454_DFA_H
