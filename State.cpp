//
// Created by chris on 2/24/21.
//

#include "State.h"

using namespace std;

State::State(string s) {
    stateOnA = s + 'a';
    stateOnB = s + 'b';
    stateOnC = s + 'c';
    stateOnD = s + 'd';
    accept = false;
    if (s.length() <= 5) {
        accept = true;          //if the string is less than 5 it is accepted
        stateName = s;

    }else if (s.length() > 5) {
        deque<char> buffer;

        for (int i = 0; i <= s.length(); i++) {

            if (i >= 6) {
                if (validity(buffer) && i <= s.length()-1) {            //if the string is valid and has more chars to add
                    buffer.pop_front();
                    buffer.push_back(s[i]);
                }else if (validity(buffer)) {                           //if the string is valid and we are at the last char
                    accept = true;
                    for (char s:buffer) {
                        stateName.push_back(s);
                    }
                }else {
                    stateName = s;
                    this->encode();
                    accept = false;
                }
            }else {
                buffer.push_back(s[i]);
            }
        }
    }
    this->encode();
}

void State::getStateName() {
    cout<<stateName<<endl;
    //cout<<stateOnA<<endl<<stateOnB<<endl<<stateOnC<<endl<<stateOnD<<endl;
}

void State::getStateNumber() {
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
    if (accept == 1) {
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


    }else {
        stateNumber = -1;
    }
}

string State::decode() {                //turns the state number back into string

}
