#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
typedef map<string,vector<string> > Map;

int main() {
    string s,sortedString;
    Map m;
    while(cin >> s) {
        sortedString = s;
        sort(sortedString.begin(),sortedString.end());
        m[sortedString].push_back(s);
    }
    for (Map::iterator itr = m.begin(); itr != m.end(); itr++) {
        copy(itr->second.begin(),itr->second.end(),ostream_iterator<string>(cout," "));
        cout << endl;
    }

    return 0;
}
