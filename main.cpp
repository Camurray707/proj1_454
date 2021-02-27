#include <iostream>
#include "State.h"
#include "DFA.h"
#include <math.h>

using namespace std;



int main() {

    //badaabcbcdcabad: reject
    //abbccdaabca: accept

    State test("babca");
    cout<<test.encode();





    return 0;
}



