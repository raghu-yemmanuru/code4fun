#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ncr(string s, int r, string result) {
    if (result.size() == r) {
        cout << result << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            continue;
        }
        ncr(s.substr(i+1), r, result+s[i]);
    }
}

int main() {
    int r;
    cin >> r;
    
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    
    ncr(s,r,"");
}
