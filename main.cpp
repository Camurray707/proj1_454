#include <iostream>
#include "State.h"
#include "DFA.h"
#include "DFAList.h"
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
    //12:553656

    DFAList newDFA;
    cout<<newDFA.count(12);


    return 0;
}



