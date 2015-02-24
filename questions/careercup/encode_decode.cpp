#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

typedef vector<string> vs;
char ESCAPE = 'E';
char SPLIT = 'S';

string encode(const vs &tokens) {
    string toReturn;
    for (int i = 0; i < tokens.size(); i++) {
        for (int j = 0; j < tokens[i].size(); j++) {
            if (tokens[i][j] == ESCAPE || tokens[i][j] == SPLIT) {
                toReturn.push_back(ESCAPE);
                toReturn.push_back(tokens[i][j]);
            } else {
                toReturn.push_back(tokens[i][j]);
            }
        }
        toReturn.push_back(SPLIT);
    }

    return toReturn;
}

vs decode(const string &s) {
    vs toReturn;
    string token;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ESCAPE) {
            i++;
            if (i >= s.size()) {
                cout << "Invalid Format";
                break;
            }
            token.push_back(s[i]);
        } else if (s[i] == SPLIT) {
            toReturn.push_back(token);
            token.clear();
        } else {
            token.push_back(s[i]);
        }
    }
    if (token.size()) {
        toReturn.push_back(token);
        token.clear();
    }
    return toReturn;
}

int main() {
    vs tokens;
    string s;
    while(cin >> s) {
        tokens.push_back(s);
    }
    string eStr = encode(tokens);
    cout << eStr << endl;
    vs toReturn = decode(eStr);
    copy(toReturn.begin(),toReturn.end(),ostream_iterator<string>(cout," "));
    cout << endl;
}
