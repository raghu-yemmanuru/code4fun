#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
struct interval {
    int beg,end;
    interval(int _b, int _e):beg(_b),end(_e){}
};

struct intervalCompare {
    bool operator() (const interval &lhs, const interval &rhs) {
        return make_pair(lhs.beg,lhs.end) < make_pair(rhs.beg,rhs.end);
    }
};

typedef vector<interval> vint;

vint merge(const vint &input) {
    stack<interval> s;
    for (int i = 0; i < input.size();i++) {
        if (s.empty() || s.top().end < input[i].beg) {
            s.push(input[i]);
        } else {
            interval tp = s.top();
            s.pop();
            s.push(interval(tp.beg,max(tp.end,input[i].end)));
        }
    }
    vint toReturn;
    while (!s.empty()) {
        toReturn.push_back(s.top());
        s.pop();
    }
    reverse(toReturn.begin(),toReturn.end());
    return toReturn;
}

void printDisjoints(const vint &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "( " << v[i].beg << " " << v[i].end << ") ";
    }
    cout << endl;
    for (int i = 1; i < v.size(); i++) {
        cout << "( " << v[i-1].end+1 << " " << v[i].beg-1 << ") ";
    }
    cout << endl;
}


int main() {
    vint v;
    int x,y;
    while(cin >> x >> y) {
        v.push_back(interval(x,y));
    }
    sort(v.begin(),v.end(),intervalCompare());
    //printDisjoints(v);
    v = merge(v);
    printDisjoints(v);
}
