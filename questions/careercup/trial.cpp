#include <iostream>
#include <string>

using namespace std;

bool isBalanced(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
        } else if (s[i] == ')') {
            count--;
            if (count < 0) {
                return false;
            }
        }
    }
    
    return (count == 0);
}

int main() {
    string s;
    cin >> s;
    if (isBalanced(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
