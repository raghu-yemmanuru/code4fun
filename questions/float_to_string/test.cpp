#include <iostream>
#include <string>

using namespace std;

string float_to_str(float f) {
    long l = 0;
    int count = 0;
    string toRet;
    bool decimal = false;
    bool negative = false;
    cout << "float " << f << endl;

    if (f < 0) {
        negative = true;
        f = 0.0f-f;
    }

    l = (long) f;
    while (l != f) {
        decimal = true;
        f = f*10;
        l = (long) f;
        count++;
    }

    while (l) {
        if (decimal && count == 0) {
            toRet.push_back('.');
        }
        char val = (l%10)+'0';
        cout << val << endl;
        toRet.push_back((l%10)+'0');
        l = l/10;
        count--;
    }

    if (negative) {
        toRet.push_back('-');
    }
    reverse(toRet.begin(),toRet.end());
    cout << "toRet " << toRet << endl;
    return toRet;
}


int main() {
    float f;
    cin >> f;
    cout << float_to_str(f) << endl;
    return 0;
}
