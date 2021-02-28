//
// Created by chris on 2/24/21.
//

#ifndef CS_454_STATE_H
#define CS_454_STATE_H

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

class State {

public:
    State(std::string s);

    void getStateName();
    void getStateNumber();



private:
    bool accept;

    std::string decode();
    void encode();

    std::string stateName;
    int stateNumber;

    std::string stateOnA;
    std::string stateOnB;
    std::string stateOnC;
    std::string stateOnD;

    bool validity(std::deque<char> d);


};


#endif //CS_454_STATE_H
