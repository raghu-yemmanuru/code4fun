#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iterator>


using namespace std;
struct point {
    int x, y;
    point(int _x, int _y):x(_x),y(_y){}
};

struct Dist {
    int dist;
    int id;
    Dist(int _d, int _i):dist(_d),id(_i){}
};

int findDist(const point &p0, const point &p1) {
    return (p1.x-p0.x)*(p1.x-p0.x) + (p1.y-p0.y)*(p1.y-p0.y);
}

struct pointCompare {
    point p0;
    pointCompare(point _p0):p0(_p0){}
    bool operator()(const point &lhs, const point &rhs) {
        return findDist(lhs,p0) < findDist(rhs,p0);
    }
};

typedef vector<point> vp;
typedef vector<Dist> vd;
typedef priority_queue<point,vp,pointCompare> pqp;


vp top3(vp &input) {
    point center(0,0);
    pointCompare compare(center);
    pqp pq(compare);
    for (int i = 0; i < input.size(); i++) {
        if(pq.size() < 3) {
            pq.push(input[i]);
        } else if (findDist(input[i],center) < findDist(pq.top(),center)) {
            pq.pop();
            pq.push(input[i]);
        }
    }
    vp result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

void partitionVector(vd &v) {
    int low = 0, high = v.size()-1;
    int k = 3;
    while (low <= high) {
        Dist pivot = v[high];
        int i = low-1;
        for (int j = low; j < high; j++) {
            if (v[j].dist < pivot.dist) {
                swap(v[i+1],v[j]);
                i++;
            }
        }
        swap(v[i+1],v[high]);
        int count = low - i + 1;
        if (count == k) {
            return;
        } else if (count < k) {
            low = i + 2;
            k = k - count;
        } else {
            high = i;
        }
    }
    return;
}

vp top3_v2(vp &input) {
    vd v;
    point center(0,0);
    for(int i = 0; i < input.size(); i++) {
        v.push_back(Dist(findDist(center,input[i]),i));
    }
    partitionVector(v);

    vp result;
    for (int i = 0; i < 3; i++) {
        result.push_back(input[v[i].id]);
    }

    return result;
}

int main() {
    int x, y;
    vp v;
    while(cin >> x >> y) {
        v.push_back(point(x,y));
    }

    vp result = top3(v);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].x << " " << result[i].y << endl;
    }

    vp result2 = top3_v2(v);
    for (int i = 0; i < result.size(); i++) {
        cout << result2[i].x << " " << result2[i].y << endl;
    }
}
