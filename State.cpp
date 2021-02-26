//
// Created by chris on 2/24/21.
//

#include "State.h"

using namespace std;

State::State() {
    accept = false;
    stateName = "";
}

string State::getStateName() {return stateName;}

void State::setStateName(string s) {
    this->stateName = s;
};

void State::createStates(int n) {

    State emptyState;
    tuple<char,State> empty (' ', emptyState);
    myStates.push_back(empty);

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 4; i++) {
            char input;

            if (i == 0) { input = 'a'; }
            else if (i == 1) { input = 'b'; }
            else if (i == 2) { input = 'c'; }
            else { input = 'd'; }

            State newState;
            newState.setStateName(this->getStateName() + input);

            tuple<char, State> inputA(input, newState);
            newState.myStates.push_back(inputA);

            newState.getStateName();
            newState.getMyStates();
        }
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

