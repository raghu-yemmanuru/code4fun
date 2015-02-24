#include <iostream>
#include <string>

using namespace std;

int validCombo(char ch1, char ch2) {
    int num = (ch1-'0')*10 + (ch2-'0');
    return (num >= 0 && num <= 25);
}

int maxComb(string &s) {
    if (s.size() == 0) {
        return 0;
    }
    int a = 1, b = 1, c = 1;
    for (int i = 1; i < s.size(); i++) {
        c = b;
        if (validCombo(s[i-1],s[i])) {
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
    cout << "Max Combintions " << maxComb(s) << endl;
}
