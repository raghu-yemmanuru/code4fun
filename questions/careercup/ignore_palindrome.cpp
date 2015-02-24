#include <iostream>
#include <string>
#include <locale>

using namespace std;
bool isPalindrome(string &s) {
    locale loc;
    int i = 0, j = s.size()-1;
    while (i <= j) {
        if (!isalpha(s[i])) {
            i++;
        } else if (!isalpha(s[j])) {
            j--;
        } else if (tolower(s[i],loc) == tolower(s[j],loc)) {
            i++;
            j--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    getline(cin,s);
    if (isPalindrome(s)) {
        cout << "Palindrome!!!" << endl;
    } else {
        cout << "Not a palindrome!!!" << endl;
    }
}
