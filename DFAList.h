//
// Created by chris on 3/3/21.
//

#ifndef CS_454_DFALIST_H
#define CS_454_DFALIST_H

#include <iostream>
#include "State.h"



class DFAList {

public:
    DFAList();
    DFAList(int n);

    int count(int n);
    int count2(int n);

private:

    State* myDFA;
    State* level5;

    bool validity(std::string s);

    std::string decode(int n);

    int encode(std::string s);
};


#endif //CS_454_DFALIST_H
