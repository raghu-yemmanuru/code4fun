#include <iostream>
#include<fstream>
#include <map>

using namespace std;

typedef multimap<string,int> Mmap;
typedef Mmap::iterator MIter;

int main() {
    Mmap m;
    string s;
    ifstream ifs("abcd.txt");
    int total = 0;
    while (ifs >> s) {
        m.insert(make_pair(s,++total));
    }

    for (MIter itr = m.begin(); itr != m.end(); itr = m.upper_bound(itr->first)) {
        pair<MIter,MIter> p = m.equal_range(itr->first);
        cout << itr->first << " ";
        for (MIter tItr = p.first; tItr != p.second; tItr++)
            cout << tItr->second << " ";
        cout << endl;
    }

    return 0;
}
