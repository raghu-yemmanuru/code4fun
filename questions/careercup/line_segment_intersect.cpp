#include <iostream>
#include <vector>

using namespace std;
struct point {
    int x,y;
    point(int _x, int _y):x(_x),y(_y){}
    point operator-(point rhs) {
        return point(x-rhs.x,y-rhs.y);
    }
};
typedef pair<point,point> Line;

int crossProduct(point p0,point p1) {
    return (p0.x*p1.y - p1.x*p0.y);
}

int direction (Line &l, point &p2) {
    point p0 = l.first;
    point p1 = l.second;
    return crossProduct(p1-p0,p2-p0);
}

bool onSegment(Line &l, point &p2) {
    point p0 = l.first;
    point p1 = l.second;

    if (p2.x >= min(p0.x,p1.x) && p2.x <= max(p0.x,p1.x) &&
        p2.y >= min(p0.y,p1.y) && p2.y <= max(p0.y,p1.y)) {
            return true;
    }
    return false;
}

bool intersect(Line l1, Line l2) {
    int d1 = direction(l1,l2.first);
    int d2 = direction(l1,l2.second);
    int d3 = direction(l2,l1.first);
    int d4 = direction(l2,l1.second);
    if (d1*d2 < 0 && d3*d4 < 0) {
        return true;
    }
    if (d1 == 0 && onSegment(l1,l2.first)) {
        return true;
    }
    if (d2 == 0 && onSegment(l1,l2.second)) {
        return true;
    }
    if (d3 == 0 && onSegment(l2,l1.first)) {
        return true;
    }
    if (d4 == 0 && onSegment(l2,l1.second)) {
        return true;
    }

    return false;
}

int main() {
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        Line l1 = make_pair(point(x1,y1),point(x2,y2));
        Line l2 = make_pair(point(x3,y3),point(x4,y4));
        if (intersect(l1,l2)) {
            cout << "Intersect!!!" << endl;
        } else {
            cout << "Not Intersect!!!" << endl;
        }
    }
}

