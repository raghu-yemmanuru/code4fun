#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef vector<int> vi;

int validCombo(char ch1, char ch2) {
    int num = (ch1-'0')*10 + (ch2-'0');
    if (num <= 26 && num > 0) {
        return true;
    } else {
        return false;
    }
}
int totalCombs(string &s) {
    vi v(s.size()+1,1);
    if (s.size() == 0) {
        return 1;
    }
    for (int i = 2; i <= s.size(); i++) {
        v[i] = v[i-1];
        if (validCombo(s[i-2],s[i-1])) {
            v[i] += v[i-2];
        }
    }
    return v[s.size()];
}

int main() {
    string s;
    cin >> s;
    cout << "Total Combinations " << totalCombs(s) << endl;
}
