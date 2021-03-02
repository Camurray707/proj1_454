//
// Created by chris on 2/24/21.
//

#include "DFA.h"

using namespace std;

DFA::DFA() {

}

mpz_class DFA::count(int n) {

    string emptyString = "";                //start string of empty string
    State newState(emptyString);            //starting state
    queue<State> tempQueue;                 //temporary queue to hold new states
    queue<State> currQueue;                 //queue being counted
    currQueue.push(newState);

    mpz_class count = 1;
    int stringSize = 0;


    while (stringSize < n) {


//            if (currQueue.front().isValid())
//                count++;

            for (int j = 0; j < 4 * pow(4,stringSize); j++) {

                switch (j) {
                    case 0: {
                        State tempStateA(currQueue.front().getNextStates(0));
                        if (tempStateA.isValid()) count++;
                        tempQueue.push(tempStateA);
                    }
                        break;
                    case 1: {
                        State tempStateB(currQueue.front().getNextStates(1));
                        if (tempStateB.isValid()) count++;
                        tempQueue.push(tempStateB);
                    }
                        break;
                    case 2: {
                        State tempStateC(currQueue.front().getNextStates(2));
                        if (tempStateC.isValid()) count++;
                        tempQueue.push(tempStateC);
                    }
                        break;
                    case 3: {
                        State tempStateD(currQueue.front().getNextStates(3));
                        if (tempStateD.isValid()) count++;
                        tempQueue.push(tempStateD);
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
    return count;
}