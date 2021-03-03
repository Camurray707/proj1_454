//
// Created by chris on 2/24/21.
//

#include "DFA.h"

using namespace std;

DFA::DFA() {

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


//            if (currQueue.front().isValid())
//                count++;

            for (int j = 0; j < 4 * pow(4,stringSize); j++) {

                switch (j%4) {
                    case 0: {
                        State tempStateA(currQueue.front().getNextStates(0));
                        if (tempStateA.isValid() && stringSize == n-1) count++;
                        if (stringSize < 6) tempQueue.push(tempStateA);
                    }
                        break;
                    case 1: {
                        State tempStateB(currQueue.front().getNextStates(1));
                        if (tempStateB.isValid() && stringSize == n-1) count++;
                        if (stringSize < 6) tempQueue.push(tempStateB);
                    }
                        break;
                    case 2: {
                        State tempStateC(currQueue.front().getNextStates(2));
                        if (tempStateC.isValid() && stringSize == n-1) count++;
                        if (stringSize < 6) tempQueue.push(tempStateC);
                    }
                        break;
                    case 3: {
                        State tempStateD(currQueue.front().getNextStates(3));
                        if (tempStateD.isValid() && stringSize == n-1) count++;
                        if (stringSize < 6) {
                            tempQueue.push(tempStateD);
                            currQueue.pop();
                        }
                        }
                        break;
                }
                if (currQueue.empty()) {
                    currQueue = tempQueue;
                    int tempSize = tempQueue.size();
                    queue<State> empty;
                    swap(tempQueue, empty);
                    if (stringSize == n - 1) return count;
                    stringSize++;
                }
                if(stringSize >= 6) {                   //currQueue now holds all states of strings length 6
                    tempQueue = currQueue;

                    while ( stringSize <= n) {

                        //for (int i = 0; i < currQueue.size(); i++) {
                            for (int j = 0; j < 4 * pow(4, stringSize); j++) {

                                switch (j % 4) {

                                    case 0: {
                                        State tempStateA(currQueue.front().getNextStates(0));
                                        if (tempStateA.isValid() && stringSize ==  n-1) count++;
                                    }
                                        break;
                                    case 1: {
                                        State tempStateB(currQueue.front().getNextStates(1));
                                        if (tempStateB.isValid() && stringSize == n-1) count++;
                                    }
                                        break;
                                    case 2: {
                                        State tempStateC(currQueue.front().getNextStates(2));
                                        if (tempStateC.isValid() && stringSize == n-1) count++;
                                    }
                                        break;
                                    case 3: {
                                        State tempStateD(currQueue.front().getNextStates(3));
                                        if (tempStateD.isValid() && stringSize == n-1) count++;
                                        currQueue.pop();
                                    }
                                        break;
                                }

                                if (currQueue.empty()) {
                                    currQueue = tempQueue;
                                    if (stringSize == n - 1) return count;
                                    stringSize++;
                                }


                            }
                        //}
                    }
                }
            }
    }
    cout<<"TEST: "<<currQueue.size()<<endl;
    return count;
}