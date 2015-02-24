#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<string> vs;
typedef map<char,int> Map;
typedef map<char,bool> Mapb;

int count(vs v) {
    Map m;
    for (int i = 0; i < v.size(); i++) {
        sort(v[i].begin(),v[i].end());
        for (int j = 0; j < v[i].size(); j++) {
            if (j > 0 && v[i][j] == v[i][j-1]) {
                continue;
            }
            m[v[i][j]]++;
        }
    }

    int total = 0;
    for (Map::iterator itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second == v.size()) {
            cout << itr->first << endl;
            total++;
        }
    }
    return total;
        
}

int main() {
    string s;
    vs v;
    while(cin >> s) {
        v.push_back(s);
    }
    cout << "Output is " << count(v) << endl;
}
