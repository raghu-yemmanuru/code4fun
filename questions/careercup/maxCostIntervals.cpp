#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct interval {
    int start, end,cost;
    interval(int _s, int _e,int _c):start(_s),end(_e),cost(_c){}
};

struct intervalCompare {
    bool operator()(const interval &lhs, const interval &rhs) {
        return lhs.end < rhs.end;
    }
};
typedef vector<interval> vint;
typedef vector<int> vi;

int compatibleCost(const vint &v, int i, const vi &f) {
    int j = i-1;
    while (j >= 0) {
        if (v[j].end < v[i].start) {
            break;
        }
        j--;
    }
    return (j >= 0 ? f[j+1]:0);
}

int maxCost(vint &v) {
    sort(v.begin(),v.end(),intervalCompare());
    vi f(v.size()+1,0);
    for (int i = 1; i <= v.size(); i++) {
        int costSofar = compatibleCost(v,i-1,f);
        f[i] = max(f[i-1], costSofar + v[i-1].cost);
    }
    return f[v.size()];
}

int main() {
    int start,end,cost;
    vint v;
    while(cin >> start >> end >> cost) {
        v.push_back(interval(start,end,cost));
    }
    cout << "Max cost " << maxCost(v) << endl;
}
