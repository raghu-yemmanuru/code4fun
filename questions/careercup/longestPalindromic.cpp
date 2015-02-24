#include <iostream>
#include <string>
using namespace std;

string palindrome(const string &s, int low, int high) {
    int count = 0;
    if (low > high) {
        return "";
    }
    while(low >= 0 && high < s.size() && s[low] == s[high]) {
        count += 2;
        low--;
        high++;
    }
    return s.substr(low+1,high-low-1);
}

string longestPalindrome(string &s) {
    int maxLen = -1;
    string result;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        temp = palindrome(s,i,i);
        if (temp.size() > result.size()) {
            result = temp;
        }
        temp = palindrome(s,i,i+1);
        if (temp.size() > result.size()) {
            result = temp;
        }
    }
    return result;
}

int main() {
    string s;
    while(cin >> s) {
        cout << longestPalindrome(s) << endl;
    }
}
