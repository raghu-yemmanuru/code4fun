#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(string s, string result) {
    if (result.size()) {
        cout << result << endl;
    }
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            continue;
        }
        permute(s.substr(0,i) + s.substr(i+1),result+s[i]);
    }
}

void power(string s, string result) {
    if (result.size()) {
        cout << result << endl;
    }
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            continue;
        }
        power(s.substr(i+1),result+s[i]);
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    //power(s,"");
    permute(s,"");
}
