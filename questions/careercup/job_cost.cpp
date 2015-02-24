#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct job {
    int start;
    int end;
    int cost;
    job(int _start,int _end, int _cost):start(_start),end(_end),cost(_cost){}
};

struct compareJobs {
    bool operator() (const job &lhs, const job &rhs) {
        if (lhs.start == rhs.start) {
            return lhs.end < rhs.end;
        }
        return lhs.start < rhs.start;
    }
};

int maxCost(vector<job> &v) {
    sort(v.begin(),v.end(),compareJobs());
    stack<job> s;

    for (int i = 0; i < v.size(); i++) {
        if (s.empty() || s.top().end < v[i].start) {
            s.push(v[i]);
            continue;
        }
        while(!s.empty() && s.top().end >= v[i].start) {
            s.pop();
        }
    }

    int cost = 0;
    while(!s.empty()) {
        cost += s.top().cost;
        s.pop();
    }

    return cost;
}
        
int main() {
    int start,end,cost;
    vector<job> v;
    while(cin >> start >> end >> cost) {
        v.push_back(job(start,end,cost));
    }

    cout << "Maximum Cost is " << maxCost(v) << endl;
}
