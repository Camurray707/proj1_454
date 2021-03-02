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
    State();
    State(std::string s);

    void getStateName();        //print state name
    void getStateNumber();      //print state id
    bool isValid();             //return true if valid string
    std::string getNextStates(int n);


private:
    bool accept;                //accept or reject state
    std::string stateName;      //string w
    int stateNumber;            //integer value of state after encoded


    std::string decode();       //fixme:: function to decode integer value into state string
    void encode();              //function to encode state string into integer value

    std::string stateOnA;
    std::string stateOnB;
    std::string stateOnC;
    std::string stateOnD;

    bool validity(std::deque<char> d);      //function to test if string w is part of language L


};


#endif //CS_454_STATE_H
