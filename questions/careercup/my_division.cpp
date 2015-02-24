#include <iostream>
using namespace std;

int add(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return add (x^y, (x&y) << 1);
    }
}

int sub(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return add (x, add(~y,1));
    }
}

int divide(int x, int y) {
    int mask = 1;
    int quotient = 0;
    while (y < x) {
        y <<= 1;
        mask <<= 1;
    }
    while (mask > 1) {
        y >>= 1;
        mask >>= 1;
        if (x >= y) {
            x = sub(x,y);
            quotient |= mask;
        }
    }
    return quotient;
}

int multiply(int x, int y) {
    int r = 0;
    int count = 0;
    while (y) {
        if (y&1) {
            r = add(r,(x << count));
        }
        count++;
        y >>= 1;
    }
    return r;
}
    
/*int divide(int numerator, int denominator) { 

    int mask = 0x1; 
    int quotient = 0; 

    cout << numerator << " " << denominator << endl;
    while (denominator <= numerator) { 
    denominator <<= 1; 
    mask <<= 1; 
    } 
    cout << numerator << " " << denominator << " " << mask << endl;

    while (mask > 1) { 
        cout << denominator << " " << numerator << " " << mask << endl;
        denominator >>= 1; 
        mask >>= 1; 
        if (numerator >= denominator) { 
            numerator = sub(numerator,denominator);
            //numerator -= denominator; 
            quotient |= mask; 
        } 
        cout << quotient << endl;
    } 

    return quotient; 
}*/

int main() {
    int n,d;
    cin >> n >> d;
    cout << divide(n,d) << endl;
    cout << multiply(n,d) << endl;
}
