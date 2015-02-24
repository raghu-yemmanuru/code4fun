#include <iostream>
#include <string>

using namespace std;

bool Palindrome(const string &s) {
    int l = 0, r = s.size()-1;
    while(l <= r) {
        while(tolower(s[l]) < 'a' || tolower(s[l]) > 'z') {
            l++;
        }
        while(tolower(s[r]) < 'a' || tolower(s[r]) > 'z') {
            r--;
        }
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    string s;
    getline(cin,s);
    if (Palindrome(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
