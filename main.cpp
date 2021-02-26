#include <iostream>
#include <gmpxx.h>
#include "State.h"
#include "StateTest.h"
#include <math.h>

using namespace std;


mpz_class count(int input);
mpz_class minString();
void createDFA();

int main() {

    //badaabcbcdcabad: reject
    //abbccdaabca: accept


    StateTest tet("abbccdaabca");




    return 0;
}

mpz_class count(int input) {
    return input;
}

mpz_class minString() {

}

void createDFA() {
    State newState;

        newState.createStates(1);

        newState.getStateName();
        newState.getMyStates();
}
