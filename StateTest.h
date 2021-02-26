//
// Created by chris on 2/24/21.
//

#ifndef CS_454_STATETEST_H
#define CS_454_STATETEST_H

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

class StateTest {

public:
    StateTest(std::string s);

    void getState();

private:
    bool accept;
    std::string stateName;
    std::string stateOnA;
    std::string stateOnB;
    std::string stateOnC;
    std::string stateOnD;

    bool validity(std::deque<char> d);


};


#endif //CS_454_STATETEST_H
