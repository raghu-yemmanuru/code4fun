#include <iostream>
#include <string>
#include <vector>

using namespace std;

int possible(string &s, int i, int j) {
    int val;
    if (s[i] == '0') {
        return false;
    }
    val = s[j]-'0' + (s[i]-'0')*10;
    return val < 26;
}


int total_strings(string &s) {
    int a,b,c;
    if (s.size() == 0) {
        return 0;
    } else if (s.size() == 1) {
        return 1;
    }

    a = 1, b = 1;
    if (possible(s,0,1)) {
        b++;
    }
    c = b;

    for (int i = 2; i < s.size(); i++) {
        c = b;
        if (possible(s,i-1,i)) {
            c += a;
        }
        a = b;
        b = c;
    }

    return c;
}

int main() {
    string s;
    cin >> s;
    cout << "Total possible strings " << total_strings(s) << endl;
    return 0;
}


