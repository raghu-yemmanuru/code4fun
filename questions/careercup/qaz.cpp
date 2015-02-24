#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef multiset<int> si;

void findQaz(const vi &v, vi &q) {
    si s;
    si::iterator itr;
    int qaz;
    for (int i = v.size()-1; i >= 0; i--) {
       itr = s.upper_bound(v[i]);
       qaz = distance(itr,s.end());
       q[i] = qaz;
       s.insert(v[i]);
    }
    return;
}

int main() {
    vi v,q;
    int num;
    while(cin >> num) {
        v.push_back(num);
    }
    q.assign(v.size(),0);
    findQaz(v,q);
    
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    copy(q.begin(),q.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    
}
