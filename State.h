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
#include <gmpxx.h>

class State {

public:
    State();
    State(std::string s);

    std::string getStateName();        //print state name
    int getStateNumber();      //print state id
    bool isValid();             //return true if valid string
    int getLevel();

    std::string getNextStates(int n);
    std::string decode(int n);  //function to decode integer n into string


private:
    std::string stateName;      //string w
    bool accept;                //accept or reject state
    int stateNumber;            //integer value of state after encoded
    int stateLevel;

    void encode();              //function to encode state string into integer value

    std::string stateOnA;
    std::string stateOnB;
    std::string stateOnC;
    std::string stateOnD;

    bool validity(std::deque<char> d);      //function to test if string w is part of language L
};


#endif //CS_454_STATE_H
