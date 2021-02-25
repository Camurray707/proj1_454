//
// Created by chris on 2/24/21.
//

#include "State.h"

using namespace std;

string State::getStateName() {return stateName;}

void State::setStateName(string s) {
    this->stateName = s;
};

void State::createStates(string s) {
    this->setStateName(s);

    for (int i = 0; i < 4; i++) {
        char input;

        if (i == 0) {input = 'a';}
        else if (i == 1) {input = 'b';}
        else if (i == 2) {input = 'c';}
        else {input = 'd';}

        State newState;
        newState.setStateName(s+input);

        tuple<char, State> inputA(input, newState);
        myStates.push_back(inputA);

    }
};



void State::getMyStates() {
    cout<<"------"<<"State "<<this->getStateName()<<"------"<<endl;
    for (tuple<char, State> s: myStates) {
        cout<<"Input "<<get<0>(s)<<"->"<<" state "<<get<1>(s).stateName<<endl;
    }
}

void State::determineState() {
    if (stateName.length() <= 5) {
        accept = true;
        return;
    }else {
        vector<char> buffer;

    }
}

