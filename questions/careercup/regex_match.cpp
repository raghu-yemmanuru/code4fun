#include <iostream>
#include <string>

using namespace std;

bool match(string &, int, string &, int);
bool match_star(char r,string &P, int i, string &T, int j) {
    do {
        if (match(P,i,T,j)) {
            return true;
        }
    } while(j < T.size() && (r == T[j++] || r == '.'));
    return false;
}

bool match(string &P, int i, string &T, int j) {
    // If we have reached end of patter we are done
    if (i >= P.size()) {
        return true;
    }
    // If we have reached end of text, we can never be done so false
    if (j > T.size()) {
        return false;
    }

    // If we find $ and if its last character then text should be done
    if (P[i] == '$' && i == P.size()-1) {
        return (j == T.size());
    }

    // If we encounter a * then keep matching the text as long as previous character of pattern
    // can consume text
    if (P[i+1] == '+') {
        if (P[i] == T[j]) {
            return match_star(P[i],P,i+2,T,j);
        }
    } else if (P[i+1] == '*') {
        return match_star(P[i],P,i+2,T,j);
    // Last case is check for just a single . or a realmatch
    } else if ((P[i] == '.' || P[i] == T[j])) {
        return match(P,i+1,T,j+1);
    }

    return false;
}

bool reg_match(string &P, string &T) {
    // handle ^ as special symbol
    if (P[0] == '^') {
        return match(P,1,T,0);
    }

    // Loop through full text to see if there is a match
    for (int j = 0; j < T.size(); j++) {
        if (match(P,0,T,j)) {
            return true;
        }
    }
    return false;
}

int main() {
    string T,P;
    getline(cin,P);
    getline(cin,T);

    if (reg_match(P,T)) {
        cout << "Matched... " << endl;
    } else {
        cout << "No match" << endl;
    }
}
