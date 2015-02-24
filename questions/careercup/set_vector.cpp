#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    set<int> s;
    for (int i = 0; i < 10; i++) {
        s.insert(i);
    }
    vector<int> v;
    v.push_back(100);
    v.assign(s.begin(),s.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
