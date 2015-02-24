#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*struct interval {
    int s,e;
    interval(int _s,int _e):s(_s),e(_e){}
};*/
typedef pair<int,int> interval;
typedef vector<interval > vint;

int intersects(vint &v) {
    if (v.size() == 0 || v.size() == 1) {
        return v.size();
    }
    int s1,s2,e1,e2;
    bool top_intersects = false;
    int count = 1;
    for (int i = 1; i < v.size(); i++) {
        s1 = v[i-1].first,e1 = v[i-1].second;
        s2 = v[i].first,e2 = v[i].second;

        if (s2 <= e1) { // intersects previous interval
            if (!top_intersects) {
                count--;
            }
            top_intersects = true;
        } else {
            count++;
            top_intersects = false;
        }
    }

    return count;
}

int main() {
    vint v;
    int s,e;
    while (cin >> s >> e) {
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(),v.end());

    cout << "Total intersects " << intersects(v) << endl;
}
