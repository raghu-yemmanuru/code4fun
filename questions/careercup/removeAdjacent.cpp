#include <iostream>
#include <string>

using namespace std;

string removeDups(string s) {
    if (s.size() == 0) {
        return "-1";
    }
    int i = 0;
    for (; i < s.size()-1 && s[i] != s[i+1]; i++) ;

    if (i == s.size()-1) {
        return s;
    }
    return removeDups(s.substr(0,i) + s.substr(i+2));
}

int main() {
    string s;
    cin >> s;
    cout << removeDups(s) << endl;
}
