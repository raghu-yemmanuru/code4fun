#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <iterator>

using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pqi;

void usePriority(vi &v) {
    pqi p(v.begin(),v.end());
    while(!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    vi v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand()%100);
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    usePriority(v);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
