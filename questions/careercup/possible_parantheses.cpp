#include <iostream>
#include <string>

using namespace std;

void print(string s, int pos, int left, int right) {
    if (left < right || left > s.size()/2 || right > s.size()/2) {
        return;
    }
    if (pos == s.size()) {
        cout << s << endl;
        return;
    }
    s[pos] = '(';
    print(s,pos+1,left+1,right);
    s[pos] = ')';
    print(s,pos+1,left,right+1);
}

int main() {
    int num;
    cin >> num;
    string s(num*2,' ');
    print(s,0,0,0);
}
