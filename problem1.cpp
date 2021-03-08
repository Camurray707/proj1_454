#include "DFA.h"
#include <iostream>
#include <gmpxx.h>

using namespace std;

int main() {

    cout<<"Enter an integer input n for the length of the strings: ";
    int n;
    cin>>n;

    DFA test;
    cout << "Total number of accepted strings with " << n << " length: " << test.count(n) << endl;

    return 0;
}
