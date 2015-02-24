#include <iostream>
#include <string>

using namespace std;

string expand(string &s, int l, int r) {
    while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
            l--;
            r++;
    }
    return s.substr(l+1,r-l-1);
}

string maxPalindrome(string &s) {
    if (s.size() == 0) {
        return "";
    }

    string longest = s.substr(0,1);
    for (int i = 0; i < s.size(); i++) {
        string l1 = expand(s,i,i);
        if (l1.size() > longest.size()) {
            longest = l1;
        }

        string l2 = expand(s,i,i+1);
        if (l2.size() > longest.size()) {
            longest = l2;
        }
    }
    
    return longest;
}
        
int main() {
    string s;
    cin >> s;
    cout << "Max palindromic substring " << maxPalindrome(s) << endl;
}
