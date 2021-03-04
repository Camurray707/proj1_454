//
// Created by chris on 3/3/21.
//

#include "DFAList.h"

using namespace std;
DFAList::DFAList() {}
DFAList::DFAList(int n) {                        //create a linked like tree for all the states starting will empty string to state ddddd


    State* startState = new State("");
    State* tempState;
    myDFA = startState;

    string emptyString = "";                //start string of empty string

    //State* startState = new State(emptyString);            //starting state
    State* rejectState;

    queue<State*> tempQueue;                 //temporary queue to hold new states
    queue<State*> currQueue;                 //queue being counted
    currQueue.push(startState);

    int stringSize = 0;


    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 4 * pow(4, i); j++) {

            switch (j % 4) {
                case 0: {
                    State* tempStateA = new State(currQueue.front()->getNextStates(0));
                    tempQueue.push(tempStateA);
                    startState->setNextOnA(tempStateA);
                    if(tempStateA->getStateName() == "aaaaa") {
                        level5 = tempStateA;
                    }
                }
                    break;
                case 1: {
                    State* tempStateB = new State(currQueue.front()->getNextStates(1));
                    tempQueue.push(tempStateB);
                    startState->setNextOnB(tempStateB);
                }
                    break;
                case 2: {
                    State* tempStateC = new State(currQueue.front()->getNextStates(2));
                    tempQueue.push(tempStateC);
                    startState->setNextOnC(tempStateC);

                }
                    break;
                case 3: {
                    State* tempStateD = new State(currQueue.front()->getNextStates(3));
                    tempQueue.push(tempStateD);
                    startState->setNextOnD(tempStateD);
                    currQueue.pop();
                    if (currQueue.front() != nullptr) {
                        startState = currQueue.front();
                    }
                }
                    break;
            }
            if (currQueue.empty()) {
                currQueue = tempQueue;
                startState= currQueue.front();
                queue<State*> empty;
                swap(tempQueue, empty);
                stringSize++;
            }
        }
    }

}

bool DFAList::validity(string s) {                   //checks if the state is part of the language
    bool aPresent = false;
    bool bPresent = false;
    bool cPresent = false;
    bool dPresent = false;

    if (s.length() < 6) {return true;}

    deque<char> buffer;

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
        State buffer(decode(i));

        if (buffer.isValid() && buffer.getLevel() == n) {
            count++;
        }
    }
    return count;
}

int DFAList::count2(int n) {

    int count = 0;

    for (int i = 0 ; i < 10000000; i++) {

        string t = decode(i);
        bool test = validity(decode(i));
        int length = decode(i).length();
        if(i == 599999) {
            cout<<"";
        }
        if (validity(decode(i)) && decode(i).length() == n) {
            count++;
        }
    }
    return count;
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