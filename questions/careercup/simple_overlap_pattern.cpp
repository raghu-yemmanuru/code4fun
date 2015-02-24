#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
typedef vector<string> vs;
typedef map<char,vs > Map;

bool isCompatible(Map &m) {
    for (Map::iterator itr = m.begin(); itr != m.end(); itr++) {
        for (int i = 1; i < itr->second.size(); i++) {
            if (itr->second[i] != itr->second[0]) {
                return false;
            }
        }
    }
    return true;
}

bool findMatch(string P, string T, Map &m) {
    if (P.size() == 0) {
        if(T.size() != 0) {
            return false;
        }
        return isCompatible(m);
    }

    for (int i = 0; i < T.size(); i++) {
        m[P[0]].push_back(T.substr(0,i+1));
        if(findMatch(P.substr(1),T.substr(i+1),m)) {
            return true;
        }
        m[P[0]].pop_back();
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
            cout << itr->first << " => " << itr->second[0] << endl;
        }
    } else {
        cout << "No match found " << endl;
    }
}
