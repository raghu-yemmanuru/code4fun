#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <algorithm>

using namespace std;
struct interval {
    int start;
    int end;
    interval(int _start, int _end):start(_start),end(_end) {}
};

struct compareIntervals {
    bool operator()(const interval &lhs, const interval &rhs) {
        if (lhs.start == rhs.start) {
            return lhs.end < rhs.end;
        }
        return lhs.start < rhs.start;
    }
};

int main() {
    int start,end;
    vector<interval> v;
    stack<interval> s;
    while(cin >> start >> end) {
        v.push_back(interval(start,end));
    }
    sort(v.begin(),v.end(),compareIntervals());

    for (int i = 0; i < v.size(); i++) {
        if (s.empty() || s.top().end < v[i].start) {
            s.push(v[i]);
            continue;
        }
        start = s.top().start;
        end = max(s.top().end,v[i].end);
        s.pop();
        s.push(interval(start,end));
    }

    int sum = 0;
    while (!s.empty()) {
        sum += (s.top().end - s.top().start);
        s.pop();
    }

    cout << "Total coverage is " << sum << endl;
}
