//
// Created by chris on 3/3/21.
//

#include "DFAList.h"

using namespace std;
DFAList::DFAList() {}

int DFAList::count(int n) {

    int count = 0;
    string startState = "";
    string endState = "";
    for (int j = 0; j < n; j++) {
        startState.push_back('a');
        endState.push_back('d');
    }

    int startStateNumber = encode(startState);
    int endStateNumber = encode(endState);

    for (int i = startStateNumber ; i <= endStateNumber; i++) {

        if (isValid(decode(i)) && decode(i).length() == n) {
            count++;
        }
    }
    return count;
}

bool DFAList::validity(deque<char> d) {                   //checks if the state is part of the language
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
bool DFAList::isValid(string s) {
    deque<char> buffer;
    bool accept;

    for (int i = 0; i <= s.length(); i++) {
        bool val = validity(buffer);

        if (i >= 6) {
            if (val && i <= s.length()-1) {            //if the string is valid and has more chars to add
                buffer.pop_front();
                buffer.push_back(s[i]);
            }else if (val) {                           //if the string is valid and we are at the last char
                accept = true;
                for (char s:buffer) {
                }
            }else {
                accept = false;
            }
        }else {
            buffer.push_back(s[i]);
        }
    }
    return accept;
}

string DFAList::decode(int n) {                //turns the state number back into string

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

int DFAList::encode(string s) {                   //turns the state string into state number
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