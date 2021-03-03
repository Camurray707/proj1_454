#include <iostream>
#include "State.h"
#include "DFA.h"
#include <math.h>
#include <chrono>

using namespace std;



int main() {


    //badaabcbcdcabad: reject
    //abbccdaabca: accept: 4461
    //abbccdaabcaddbacdaabcdbabccd: accept: 2496

    DFA myDfa;
    cout<<myDfa.count(8);
    State test("abbccdaabcaddbacdaabcdbabccd");




    return 0;
}



