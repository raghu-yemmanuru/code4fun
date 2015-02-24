#include <iostream>
#include <string>

using namespace std;

void reverse(string &s) {
    int l = 0, r = s.size()-1;
    while (l <= r) {
        swap(s[l],s[r]);
        l++;
        r--;
    }
    return;
}

int main() {
    string s;
    while(cin >> s) {
        reverse(s);
        cout << s << endl;
    }
}
