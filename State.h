//
// Created by chris on 2/24/21.
//

#ifndef CS_454_STATE_H
#define CS_454_STATE_H

#include <vector>
#include <tuple>
#include <iostream>

class State {

public:
    std::string getStateName();
    void setStateName(std::string s);

    void createStates(std::string s);
    void getMyStates();



private:
    void determineState();
    bool accept = false;
    std::string stateName;
    std::vector<std::tuple<char, State>> myStates;    //a vector of tuples made up of input->state

};


#endif //CS_454_STATE_H
