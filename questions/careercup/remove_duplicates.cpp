#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
typedef set<char> Set;
typedef map<char,int> Map;

void removeDups1(string &s) {
    sort(s.begin(),s.end());
    int i = 0, j = 0;
    while (j < s.size()) {
        char ch = s[j++];
        int count = 1;
        while(j < s.size() && s[j] == ch) {
            count++;
            j++;
        }
        if (count == 1) {
            s[i++] = ch;
        }
    }
    s.erase(s.begin()+i,s.end());
    return;
}
void removeDups(string &str) {
    Map m;
    int i = -1;
    for (int j = 0; j < str.size(); j++) {
        m[str[j]]++;
    }

    for (int j = 0; j < str.size(); j++) {
        if(m[str[j]] == 1) {
            str[++i] = str[j];
        }
    }
    str.erase(str.begin()+i+1,str.end());
    return;
}

int main() {
    string s;
    getline(cin,s);
    string s1 = s;
    removeDups(s1);
    removeDups1(s);
    cout << s << " " << s1 << endl;
}
