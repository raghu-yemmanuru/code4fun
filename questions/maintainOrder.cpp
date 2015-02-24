#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef map<char,bool> Map;

void maintain(string &s) {
    Map m;
    int i = -1;
    for (int j = 0; j < s.size(); j++) {
        if (!m[s[j]]) {
            swap(s[i+1],s[j]);
            i++;
        }
        m[s[j]] = true;
    }

    s.erase(s.begin()+i+1,s.end());
    return;
}

int main() {
    string s;
    cin >> s;
    maintain(s);
    cout << s << endl;
}
