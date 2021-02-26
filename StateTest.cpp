//
// Created by chris on 2/24/21.
//

#include "StateTest.h"

using namespace std;

StateTest::StateTest(string s) {
    this->stateName = s;
    stateOnA = s + 'a';
    stateOnB = s + 'b';
    stateOnC = s + 'c';
    stateOnD = s + 'd';
    accept = false;
    if (s.length() <= 5) {
        accept = true;          //if the string is less than 5 it is accepted

    }else if (s.length() > 5) {
        deque<char> buffer;

        for (int i = 0; i <= s.length(); i++) {

            if (i >= 6) {
                if (validity(buffer) && i <= s.length()-1) {            //if the string is valid and has more chars to add
                    buffer.pop_front();
                    buffer.push_back(s[i]);
                }else if (validity(buffer)) {                           //if the string is valid and we are at the last char
                    accept = true;
                }else {accept = false;}
            }else {
                buffer.push_back(s[i]);
            }
        }
    }
}

void StateTest::getState() {
    cout<<stateName<<endl;
    cout<<stateOnA<<endl<<stateOnB<<endl<<stateOnC<<endl<<stateOnD<<endl;
}

bool StateTest::validity(deque<char> d) {
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


