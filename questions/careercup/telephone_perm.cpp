#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef map<char,string> Map;

void buildMap(Map &M) {
    M['2'] = "abc";
    M['3'] = "def";
    M['4'] = "ghi";
    M['5'] = "jkl";
    M['6'] = "mno";
    M['7'] = "pqrs";
    M['8'] = "tuv";
    M['9'] = "wxyz";
}

void permute(string s, Map &m, string result) {
    if (s.size() == 0) {
        cout << result << endl;
        return;
    }
    for (int i = 0; i < m[s[0]].size(); i++) {
        permute(s.substr(1),m,result+m[s[0]][i]);
    }
}

int main() {
    string s;
    cin >> s;
    Map m;
    buildMap(m);
    permute (s,m,"");
}
