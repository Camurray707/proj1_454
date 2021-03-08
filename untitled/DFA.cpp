//
// Created by chris on 3/7/2021.
//

#include "DFA.h"

using namespace std;

DFA::DFA() {

    vector<int> p(SIZE, 0);
    p.at(1364) = 1;
    vector<int> c(SIZE, 0);
    this->previous = p;
    this->current = c;


    string startState = "";
    myDFA.clear();
    myDFA.push_back(startState);
    char alpha[4] = {'a', 'b', 'c', 'd'};

    for (int i = 0; i < 341; i++) {
        for (int j = 0; j < 4; j++) {
            myDFA.push_back(myDFA[i] + alpha[j]);
        }
    }
}

int DFA::encode(std::string s) {
    int stateNumber = 0;
    int stateSize = s.length() - 1;

    for (char c : s) {
        switch (c) {
            case 'a':
                stateNumber = stateNumber + (1 * pow(4, stateSize));
                stateSize--;
                break;
            case 'b':
                stateNumber = stateNumber + (2 * pow(4, stateSize));
                stateSize--;
                break;
            case 'c':
                stateNumber = stateNumber + (3 * pow(4, stateSize));
                stateSize--;
                break;
            case 'd':
                stateNumber = stateNumber + (4 * pow(4, stateSize));
                stateSize--;
                break;
        }
    }
    return stateNumber;
}

//s is of size 6 or below
bool DFA::isValid(std::string s) {
    if (s.size() > 6) {cout<<"Error: isValid, size of s is greater than 6."<<endl;exit(-1);}
    bool aPresent = false;
    bool bPresent = false;
    bool cPresent = false;
    bool dPresent = false;

    for (char c:s) {
        switch (c) {
            case 'a': aPresent = true;
                break;
            case 'b': bPresent = true;
                break;
            case 'c': cPresent = true;
                break;
            case 'd': dPresent = true;
                break;
        }
    }
    return aPresent && bPresent && cPresent && dPresent;
}

int DFA::window(std::string state, char c) {
    string newString = state + c;
    if (newString.size() < 6) return encode(newString);
    else if (isValid(newString)) {
        return encode(newString.substr(1,5));
    }
    return 0;
}

void DFA::determiner(std::string state) {
    int count = 0;
    char alpha[4] = {'a', 'b', 'c', 'd'};
     for (char c : alpha) {
         count += previous[window(state,c)];
     }
     current[encode(state)] = count;

}

int DFA::count(int n) {

    int count = 0;

    while (count < n ) {
        for (int i = 0; i < previous.size() - 1; i++){
            determiner(myDFA[i]);
        }
        previous = current;
        count++;
    }
    return current[0];
}


