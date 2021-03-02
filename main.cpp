#include <iostream>
#include "State.h"
#include "DFA.h"
#include <math.h>

using namespace std;



int main() {

    //badaabcbcdcabad: reject
    //abbccdaabca: accept: 4461
    //abbccdaabcaddbacdaabcdbabccd: accept: 2496

    DFA myDfa;
    cout<<myDfa.count(6);





    return 0;
}



