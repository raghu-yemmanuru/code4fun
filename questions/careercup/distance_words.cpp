#include <iostream>
#include <string>
using namespace std;

enum state_t {SPACE=0,CHAR};
int wordDistance(const string &line, const string &word1, const string &word2) {
    int count = 0;
    int i = line.find(word1);
    int j = line.find(word2);
    state_t state = CHAR;
    if (i == string::npos || j == string::npos) {
        return -1;
    }

    for (int k = i; k < j; k++) {
        if (line[k] != ' ') {
            if (state == SPACE) {
                count++;
            }
            state = CHAR;
        } else {
            state = SPACE;
        }
    }

    return count+1;
}

int main() {
    string s;
    getline(cin,s);
    string word1,word2;
    cin >> word1 >> word2;
    cout << wordDistance(s,word1,word2) << endl;
}
