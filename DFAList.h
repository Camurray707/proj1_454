//
// Created by chris on 3/3/21.
//

#ifndef CS_454_DFALIST_H
#define CS_454_DFALIST_H

#include <iostream>
#include <cmath>
#include <deque>



class DFAList {

public:
    DFAList();

    int count(int n);

private:


    bool validity(std::deque<char> d);
    bool isValid(std::string s);

    std::string decode(int n);
    int encode(std::string s);

};


#endif //CS_454_DFALIST_H
