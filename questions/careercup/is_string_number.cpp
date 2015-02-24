#include <iostream>
#include <string>

using namespace std;

bool isNumber(string &s) {
    if (s.size() == 0) {
        return false;
    }
    int i = 0;

    if (s[i] == '-') {
        i++;
    }
    int dotsSofar = 0;
    for (; i < s.size(); i++) {
        if (s[i] == '.') {
            if (dotsSofar >= 1 || i == 0 || i == s.size()-1) {
                return false;
            }
            dotsSofar++;
            continue;
        }
        if (!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    if (isNumber(s)) {
        cout << "string is a number" << endl;
    } else {
        cout << "Not a number" << endl;
    }
}
