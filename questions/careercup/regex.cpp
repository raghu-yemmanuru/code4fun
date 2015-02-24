#include <iostream>
#include <string>
using namespace std;

bool match(string,string);
bool match_star(char ch, string P, string T) {
    int i = 0;
    do {
        
        if (match(P,T.substr(i))) {
            return true;
        }
    } while(i < T.size() && (T[i++] == ch || ch == '.'));
    return false;
}

bool match(string P, string T) {
    if (P.size() == 0) {
        return true;
    }
    if (P[0] == '$' && P.size() == 1) {
        return (T.size() == 0);
    } else if (P[1] == '*') {
        return match_star(P[0],P.substr(2),T);
    } else if (P[1] == '+') {
        if (P[0] == T[0]) {
            return match_star(P[0],P.substr(2),T);
        }
    } else if (P[0] == '.' || P[0] == T[0]) {
        return match(P.substr(1),T.substr(1));
    }
    return false;
}
bool reg_match(string P, string T) {
    if (P.size() == 0) {
        return true;
    }
    if (P[0] == '^') {
        return match(P.substr(1),T);
    }
    for (int i = 0; i < T.size(); i++) {
        if (match(P,T.substr(i))) {
            return true;
        }
    }
    return false;
}

int main() {
    string P,T;
    cin >> P >> T;
    if (reg_match(P,T)) {
        cout << "Matched" << endl;
    } else {
        cout << "Does not match" << endl;
    }
}
