#include <iostream>
#include "DFAList.h"
#include <time.h>

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

    clock_t t;
    t = clock();

    DFAList newDFA;
    cout<<newDFA.count(8)<<endl;

    t = clock() - t;

    cout<<t<<((int)t)/CLOCKS_PER_SEC<<endl;

    return 0;
}



