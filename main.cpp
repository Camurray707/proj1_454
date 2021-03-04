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
    //7: 4440
    //8: 12,072
    //9: 31,584
    //10: 81,552
    //11: 211,224

    State tempState("ddddd");
    //cout<<tempState.decode(1364)<<endl;



    DFA myDfa;
    cout<<myDfa.finalCount(7);
    //cout<<myDfa.count(8);




    return 0;
}



