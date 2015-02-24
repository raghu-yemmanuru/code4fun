#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> Pair;
struct CompareY {
    bool operator()(const Pair &lhs, const Pair &rhs) {
        Pair lhs1(lhs.second,lhs.first);
        Pair rhs1(rhs.second,rhs.first);
        return lhs1 < rhs1;
    }
};

int direction (const Pair &p0, const Pair &p1, const Pair &p2) {
    // return (p1-p0)x(p2-p0)
    return (p1.first-p0.first)*(p2.second-p0.second) - (p2.first-p0.first)*(p1.second-p0.second);
}

int dist (const pair<int,int> p0, const pair<int,int> p1) {
    int x = p1.first - p0.first;
    int y = p1.second - p0.second;
    return (x*x + y*y);
}

void test(pair<int,int> p, pair<int,int> q){
}

struct CompareAngle {
    Pair p0;
    CompareAngle(Pair _p):p0(_p){}
    bool operator()(const Pair &lhs, const Pair &rhs) {
        int d = direction(p0,lhs,rhs);
        if (d > 0) {
            return true;
        }
        if (d < 0) {
            return false;
        }
        if (d == 0) {
            if (dist(p0,lhs) < dist(p0,rhs)) {
                return true;
            } else {
                return false;
            }
        }
    }
};

Pair next_to_top(vector<Pair> &v) {
    int end = v.size()-1;
    return v[end-1];
}

Pair top(vector<Pair> &v) {
    int end = v.size()-1;
    return v[end];
}

int main(int argc, char **argv) {
    vector<pair<int,int> > v;
    ifstream ifs(argv[1]);
    int x,y;
    while (ifs >> x >> y) {
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),CompareY());
    sort(v.begin()+1,v.end(),CompareAngle(v[0]));

    vector<Pair> s;
    s.push_back(v[0]);
    s.push_back(v[1]);
    s.push_back(v[2]);

    for (int i = 3; i < v.size(); i++) {
        while(direction(next_to_top(s),top(s),v[i]) <= 0) {
            s.pop_back();
        }
        s.push_back(v[i]);
    }

    for (int i = 0; i < s.size(); i++) {
        cout << "(" << s[i].first << "," << s[i].second << ")" << endl;
    }
}
