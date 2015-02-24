#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string convertFraction(double f) {
    string s;
    double r;
    while(f) {
        if (s.size() == 32) {
            return "Error";
        }
        r = 2*f;
        if (r >= 1) {
            s.push_back('1');
            f = r-1;
        } else {
            s.push_back('0');
            f = r;
        }
    }
    return s;
}

string convertInteger(int num) {
    string s;
    while (num) {
        if(num&1) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
        num >>= 1;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main() {
    double d;
    cin >> d;
    int i;
    double e;
    i = (int)d;
    e = d - i;

    cout << dec << e << endl; 

    string is = convertInteger(i);
    string fs = convertFraction(e);
    cout << is << "." << fs << endl;
}
