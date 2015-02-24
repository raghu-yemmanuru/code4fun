#include <iostream>
#include <climits>
using namespace std;

int main () {
    int n = 1024;
    int m = 21;
    int i = 2;
    int j = 6;

    int mask = ~0;

    //clear all bits less than i
    mask = mask - ((1 << i) - 1);

    // clear all bits greater than j
    mask = mask & ((1 << j+1) - 1);

    // now mask contains ones only between i and j
    cout << "mask is " << mask << endl;

    int val = n | (m&mask);
    cout << "value is " << val << endl;
}
