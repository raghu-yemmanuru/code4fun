#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef map<char,string> mvc;

void buildMap(mvc &m) {
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
}

void printAll(string s, mvc &m, string result) {
    if (s.size() == 0) {
        cout << result << endl;
        return;
    }
    for (int i = 0; i < m[s[0]].size(); i++) {
        printAll(s.substr(1,s.size()-1), m, result + m[s[0]][i]);
    }
}

int main() {
    string s;
    cin >> s;
    
    mvc m;
    buildMap(m);
    string result;
    printAll(s,m,result);
}
