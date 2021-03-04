//
// Created by chris on 2/24/21.
//

#include "DFA.h"

using namespace std;

/*   DFA constructor that creates the 1366 states starting with the empty state and ending with reject state     */
DFA::DFA() {

    string emptyString = "";                //start string of empty string

    State startState(emptyString);            //starting state
    State rejectState;

    queue<State> tempQueue;                 //temporary queue to hold new states
    queue<State> currQueue;                 //queue being counted
    currQueue.push(startState);
    myStates.push_back(startState);

    int stringSize = 0;


    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 4 * pow(4, i); j++) {

            switch (j % 4) {
                case 0: {
                    State tempStateA(currQueue.front().getNextStates(0));
                    tempQueue.push(tempStateA);
                    myStates.push_back(tempStateA);
                }
                    break;
                case 1: {
                    State tempStateB(currQueue.front().getNextStates(1));
                    tempQueue.push(tempStateB);
                    myStates.push_back(tempStateB);
                }
                    break;
                case 2: {
                    State tempStateC(currQueue.front().getNextStates(2));
                    tempQueue.push(tempStateC);
                    myStates.push_back(tempStateC);
                }
                    break;
                case 3: {
                    State tempStateD(currQueue.front().getNextStates(3));
                    tempQueue.push(tempStateD);
                    myStates.push_back(tempStateD);
                    currQueue.pop();
                }
                    break;
            }
            if (currQueue.empty()) {
                currQueue = tempQueue;
                queue<State> empty;
                swap(tempQueue, empty);
                stringSize++;
            }
        }
    }
    myStates.push_back(rejectState);
}

int DFA::countRetry(int n) {

    string emptyString = "";                //start string of empty string
    State newState(emptyString);            //starting state
    State rejectState;
    queue<State> tempQueue;                 //temporary queue to hold new states
    queue<State> currQueue;                 //queue being counted
    deque<State> DFA;
    DFA.push_back(newState);
    currQueue.push(newState);

    int count = 0;
    int stringSize = 0;


    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 4 * pow(4, i); j++) {

            switch (j % 4) {
                case 0: {
                    State tempStateA(currQueue.front().getNextStates(0));
                    tempQueue.push(tempStateA);
                    DFA.push_back(tempStateA);
                }
                    break;
                case 1: {
                    State tempStateB(currQueue.front().getNextStates(1));
                    tempQueue.push(tempStateB);
                    DFA.push_back(tempStateB);
                }
                    break;
                case 2: {
                    State tempStateC(currQueue.front().getNextStates(2));
                    tempQueue.push(tempStateC);
                    DFA.push_back(tempStateC);
                }
                    break;
                case 3: {
                    State tempStateD(currQueue.front().getNextStates(3));
                    tempQueue.push(tempStateD);
                    DFA.push_back(tempStateD);
                    currQueue.pop();
                }
                    break;
            }
            if (currQueue.empty()) {
                currQueue = tempQueue;
                queue<State> empty;
                swap(tempQueue, empty);
                stringSize++;
            }
        }
    }
    DFA.push_back(rejectState);
    return count;
}

int DFA::count(int n) {

    string emptyString = "";                //start string of empty string
    State newState(emptyString);            //starting state
    queue<State> tempQueue;                 //temporary queue to hold new states
    queue<State> currQueue;                 //queue being counted
    currQueue.push(newState);

    int count = 0;

    mpz_class prevCount = 0;
    int stringSize = 0;


    while (stringSize < n) {

            for (int j = 0; j < 4 * pow(4,n-1); j++) {

                switch (j%4) {
                    case 0: {
                        State tempStateA(currQueue.front().getNextStates(0));
                        if (tempStateA.isValid() && stringSize == n-1) count++;
                        tempQueue.push(tempStateA);
                    }
                        break;
                    case 1: {
                        State tempStateB(currQueue.front().getNextStates(1));
                        if (tempStateB.isValid() && stringSize == n-1) count++;
                        tempQueue.push(tempStateB);
                    }
                        break;
                    case 2: {
                        State tempStateC(currQueue.front().getNextStates(2));
                        if (tempStateC.isValid() && stringSize == n-1) count++;
                        tempQueue.push(tempStateC);
                    }
                        break;
                    case 3: {
                        State tempStateD(currQueue.front().getNextStates(3));
                        if (tempStateD.isValid() && stringSize == n-1) count++;
                            tempQueue.push(tempStateD);
                            currQueue.pop();
                        }
                        break;
                }
                if (currQueue.empty()) {
                    currQueue = tempQueue;
                    queue<State> empty;
                    swap(tempQueue, empty);
                    if (stringSize == n - 1) return count;
                    stringSize++;
                }
                if(stringSize >= 6) {                   //currQueue now holds all states of strings length 6
                    tempQueue = currQueue;
                    deque<State> finalQueue;
                    while (!currQueue.empty()) {
                        finalQueue.push_back(currQueue.front());
                        currQueue.pop();
                    }

                    while ( stringSize <= n) {

                        //for (int i = 0; i < currQueue.size(); i++) {
                            for (int j = 0; j < 4 * pow(4, stringSize); j++) {

                                switch (j % 4) {

                                    case 0: {
                                        State tempStateA(finalQueue.at(j%4096).getNextStates(0));
                                        if (tempStateA.isValid() && stringSize ==  n-1) count++;
                                    }
                                        break;
                                    case 1: {
                                        State tempStateB(finalQueue.at(j%4096).getNextStates(1));
                                        if (tempStateB.isValid() && stringSize == n-1) count++;
                                    }
                                        break;
                                    case 2: {
                                        State tempStateC(finalQueue.at(j%4096).getNextStates(2));
                                        if (tempStateC.isValid() && stringSize == n-1) count++;
                                    }
                                        break;
                                    case 3: {
                                        State tempStateD(finalQueue.at(j%4096).getNextStates(3));
                                        if (tempStateD.isValid() && stringSize == n-1) count++;
                                    }
                                        break;
                                }

//                                if (currQueue.empty()) {
//                                    currQueue = tempQueue;
//                                    if (stringSize == n) return count;
//                                    stringSize++;
//                                }

                                if (j > 16383)
                                {
                                    int i = 6;
                                }
                            }
                            stringSize++;
                            if (stringSize == n) return count;
                        //}
                    }
                }
            }
    }
    return count;
}

int DFA::finalCount(int n) {

    int stringSize = 6;
    int count = 0;


    for (State s : myStates) {
        if (s.getLevel() == n) {
            count++;
        }else if(s.getLevel() > n) {
            return count;
        }
    }


    if (n >= 6) {
        for (int i = 341; i < 1365; i++) {
            State tempState(myStates.at(i).getStateName());
            for (int j = 0; j < 4; j++) {
                if (validity(tempState.getNextStates(j))) {
                    count++;
                }
            }

        }
    }

    return count;
}

bool DFA::validity(string s) {                   //checks if the state is part of the language
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
