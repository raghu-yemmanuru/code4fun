#include <iostream>
#include <string>

using namespace std;
void printAll(string s,int index) {
    int i = index;

    for (; i < s.size() && s[i] != '?'; i++) ;
    if (i == s.size()) {
        cout << s << endl;
        return;
    }
    s[i] = '0';
    printAll(s,i+1);
    s[i] = '1';
    printAll(s,i+1);
}

int main() {
    string s;
    cin >> s;
    printAll(s,0);
}
