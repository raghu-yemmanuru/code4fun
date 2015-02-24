#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    map<string, int> m;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        m.insert(make_pair(s.substr(i),i));
    }

    for (map<string,int>::iterator itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->second << " ";
    }
    cout << endl;
}

