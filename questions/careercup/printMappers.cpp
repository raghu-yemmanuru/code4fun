#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef map<char,string> Map;

void buildMap(Map &m) {
    m['a'] = "@4A";
    m['f'] = "F#";
}

void permute(string s, Map &m, string result) {
    if (s.size() == 0) {
        cout << result << endl;
        return;
    }
    if (m.find(s[0]) == m.end()) {
        permute(s.substr(1),m,result+s[0]);
    } else {
        for (int i = 0; i < m[s[0]].size(); i++) {
            permute(s.substr(1),m,result+m[s[0]][i]);
        }
    }
}

int main() {
    Map m;
    buildMap(m);
    
    string s;
    cin >> s;
    
    permute(s,m,"");
}
