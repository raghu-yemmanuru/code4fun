#include <iostream>
#include <string>
using namespace std;

enum state_t {SPACE=0,CHAR};
int countWords(const string &s) {
    state_t cur = SPACE;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == '\t') {
            cur = SPACE;
        } else if (cur == SPACE) {
            cur = CHAR;
            ++count;
        }
    }

    return count;
}

int main() {
    string s;
    getline(cin,s);
    cout << countWords(s) << endl;
}
