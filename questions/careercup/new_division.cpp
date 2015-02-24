#include <iostream>
using namespace std;
typedef pair<int,int> Pair;

int add1 (int a, int b) {
    int sum = 0,carry = 0;
    do {
        sum = (a^b);
        carry = (a&b);
        a = sum;
        b = (carry << 1);
    } while(carry);
    return sum;
}

int add (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return add(a^b, ((a&b) << 1));
    }
}

int sub(int a, int b) {
    return add1 (a,add1(~b,1));
}

int multiply(int a, int b) {
    int result = 0;
    int index = 0;
    while (b) {
        if (b & 1) {
            result = add1(result,(a << index));
        }
        index++;
        b >>= 1;
    }
    return result;
}


Pair divide(int n, int d) {
    int mask = 1;
    while (d <= n) {
        mask <<= 1;
        d <<= 1;
    }

    int q = 0;
    while (mask > 1) {
        mask >>= 1;
        d >>= 1;
        if (n >= d) {
            q |= mask;
            n -= d;
        }
    }

    return make_pair(q,n);
}

int main() {
    int numerator,denominator;
    Pair p;
    while(cin >> numerator >> denominator) {
        p = divide(numerator,denominator); 
        cout << p.first << " " << p.second << endl;
        cout << multiply(numerator,denominator) << endl;
    }
}
