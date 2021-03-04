#include <iostream>
#include "DFAList.h"

using namespace std;

int main() {


    //badaabcbcdcabad: reject
    //abbccdaabca: accept: 4461
    //abbccdaabcaddbacdaabcdbabccd: accept: 2496
    //7:  4440
    //8:  12,072
    //9:  31,584
    //10: 81,552
    //11: 211,224
    //12: 553656
    //13: 1,444,728

    DFAList newDFA;
    cout<<newDFA.count(10);


    return 0;
}



