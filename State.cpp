//
// Created by chris on 2/24/21.
//

#include "State.h"

using namespace std;
State::State() {
    stateName = "REJECT STATE";
    stateNumber = -1;
    stateLevel = -1;
    accept = false;
}
State::State(string s) {
    stateOnA = s + 'a';
    stateOnB = s + 'b';
    stateOnC = s + 'c';
    stateOnD = s + 'd';
    accept = false;
    if (s.length() <= 5) {
        accept = true;          //if the string is less than 5 it is accepted
        stateName = s;
        if (s == "") stateLevel = -1;
        else {stateLevel = s.length();}

    }else if (s.length() > 5) {
        deque<char> buffer;
        
        for (int i = 0; i <= s.length(); i++) {
            bool val = validity(buffer);

            if (i >= 6) {
                if (val && i <= s.length()-1) {            //if the string is valid and has more chars to add
                    buffer.pop_front();
                    buffer.push_back(s[i]);
                }else if (val) {                           //if the string is valid and we are at the last char
                    accept = true;
                    stateLevel = s.length();
                    for (char s:buffer) {
                        stateName.push_back(s);
                    }
                }else {
                    stateName = s;
                    stateLevel = s.length();
                    accept = false;
                }
            }else {
                buffer.push_back(s[i]);
            }
        }
    }
    this->encode();
}

string State::getStateName() {
    return stateName;
}

int State::getStateNumber() {
    cout<<stateNumber<<endl;
}

bool State::isValid() {
    return accept;
}

string State::getNextStates(int n) {
    switch (n) {
        case 0: return stateOnA;
        case 1: return stateOnB;
        case 2: return stateOnC;
        case 3: return stateOnD;
    }
}


bool State::validity(deque<char> d) {                   //checks if the state is part of the language
    bool aPresent = false;
    bool bPresent = false;
    bool cPresent = false;
    bool dPresent = false;

    for (char c:d) {
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

void State::encode() {                   //turns the state string into state number
        stateNumber = 0;
        int stateSize = stateName.length() - 1;

        for (char c : stateName) {
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


    //else {
//        stateNumber = -1;
//    }
}

string State::decode(int n) {                //turns the state number back into string

    int temp = n;

    string stringName;
    deque<char> string;

    while (temp != 0) {
        switch(temp % 4) {
            case 1:
                string.push_front('a');
                temp = temp/4;

                break;
            case 2:
                string.push_front('b');
                temp = temp/4;

                break;
            case 3:
                string.push_front('c');
                temp = temp/4;

                break;
            case 0:
                string.push_front('d');
                temp = (temp/4) - 1;

                break;
        }
    }

    for (char c : string) {
        stringName.push_back(c);
    }

return stringName;
}

int State::getLevel() {
    return stateLevel;
}

State *State::getNextOnA() const {
    return nextOnA;
}

void State::setNextOnA(State *nextOnA) {
    State::nextOnA = nextOnA;
}

State *State::getNextOnB() const {
    return nextOnB;
}

void State::setNextOnB(State *nextOnB) {
    State::nextOnB = nextOnB;
}

State *State::getNextOnC() const {
    return nextOnC;
}

void State::setNextOnC(State *nextOnC) {
    State::nextOnC = nextOnC;
}

State *State::getNextOnD() const {
    return nextOnD;
}

void State::setNextOnD(State *nextOnD) {
    State::nextOnD = nextOnD;
}
