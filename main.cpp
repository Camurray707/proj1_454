#include <iostream>
#include <gmpxx.h>
#include "State.h"
#include <math.h>

using namespace std;


mpz_class count(int input);
mpz_class minString();
void createDFA();

int main() {

    State newState;
    newState.createStates("abbab");

    newState.getStateName();
    newState.getMyStates();



    return 0;
}

mpz_class count(int input) {
    return input;
}

mpz_class minString() {

}

void createDFA() {
    for (int i = 0; i < 300; i++) {
        State newState;
    }
}
