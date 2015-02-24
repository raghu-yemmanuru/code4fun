#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef map<char,string> Map;

bool findMatch(string P, string T, Map &m) {
    if (P.size() == 0) {
        return true;
    }
    if (T.size() == 0) {
        return false;
    }

    if (m.find(P[0]) != m.end()) {
        if (T.find(m[P[0]]) != 0) {
            return false;
        }
        return findMatch(P.substr(1),T.substr(m[P[0]].size()),m);
    }

    for (int i = 0; i < T.size(); i++) {
        m[P[0]] = T.substr(0,i+1);
        if(findMatch(P.substr(1),T.substr(i+1),m)) {
            return true;
        }
        m.erase(P[0]);
    }

    return false;
}

int main () {
    string P,T;
    cin >> P;
    cin >> T;
    Map m; 
    if (findMatch(P,T,m)) {
        cout << "Match found" << endl;
        for (Map::iterator itr = m.begin(); itr != m.end(); itr++) {
            cout << itr->first << " => " << itr->second << endl;
        }
    } else {
        cout << "No match found " << endl;
    }
}
