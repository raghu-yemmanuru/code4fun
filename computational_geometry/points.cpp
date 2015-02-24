#include <iostream>
#include <vector>

using namespace std;
struct point {
    int x, y;
    point(int _x, int _y): x(_x),y(_y) {}
    point operator -(const point &rhs) {
        return point(x-rhs.x,y-rhs.y);
    }
};

int cross(const point &p0, const point &p1) {
    return (p0.x*p1.y - p0.y*p1.x);
}

int direction(point &p0, point &p1, point &p2) {
    return cross(p1-p0,p2-p0);
}
    
int main() {
    point p0 = point(1,1);
    point p1 = point(3,2);
    point p2 = point(2,3);

    cout << direction(p0,p1,p2) << endl;
}
