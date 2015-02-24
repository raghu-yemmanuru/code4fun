#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef pair<int,int> Pair;
typedef vector<Pair > vp;
struct point {
    int x,y;
    point(int _x, int _y):x(_x),y(_y){}
};

point closest(vector<point> v) {
    vp xPoints;
    vp yPoints;
    int n = v.size();
    for (int i = 0; i < v.size(); i++) {
        xPoints.push_back(make_pair(v[i].x,i));
        yPoints.push_back(make_pair(v[i].y,i));
    }
    sort(xPoints.begin(),xPoints.end());
    sort(yPoints.begin(),yPoints.end());
    vector<int> leftx(n,0), rightx(n,0), upy(n,0), downy(n,0);
    for (int i = 1; i < xPoints.size(); i++) {
        leftx[i] = leftx[i-1] + abs(xPoints[i].first - xPoints[i-1].first);
        downy[i] = downy[i-1] + abs(yPoints[i].first - yPoints[i-1].first);
    }
    for (int i = xPoints.size()-1; i >= 0; i--) {
        rightx[i] = rightx[i+1] + abs(xPoints[i].first - xPoints[i+1].first);
        upy[i] = upy[i+1] + abs(yPoints[i].first - yPoints[i+1].first);
    }
    vector<int> totalX(n,0), totalY(n,0);
    for (int i = 0; i < n; i++) {
        totalX[xPoints[i].second] = leftx[i] + rightx[i];
        totalY[yPoints[i].second] = downy[i] + upy[i];
    }
    int global = numeric_limits<int>::max();
    int result = -1;
    for (int i = 0; i < n; i++) {
        if (totalX[i] + totalY[i] < global) {
            global = totalX[i] + totalY[i];
            result = i;
        }
    }
    return v[result];
}
        
    
int main() {
    vector<point> v;
    int x,y;
    while (cin >> x >> y) {
        v.push_back(point(x,y));
    }
    cout << "Closest point is " << closest(v).x << " " << closest(v).y << endl;
}
