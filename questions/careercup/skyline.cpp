#include <iostream>
#include <stack>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int> vi;

int maxArea(vector<int> &v) {
    if (v.size() == 0) {
        return 0;
    }
    stack<int> s;
    int i = 0;
    int area,max_area = numeric_limits<int>::min();
    int tp;
    int width;
    while (i < v.size()) {
        if (s.empty() || v[i] >= v[s.top()]) {
            s.push(i++);
        } else {
            tp = s.top();
            s.pop();
            if (!s.empty()) {
                width = i - s.top() - 1;
            } else {
                width = i;
            }
            area = v[tp] * (width);
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        if (!s.empty()) {
            width = i - s.top() - 1;
        } else {
            width = i;
        }
        area = v[tp]*(width);
        if (area > max_area) {
            area = max_area;
        }
    }
    
    return max_area;
}

int main() {
    vi v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    cout << "Max rectangle area is " << maxArea(v) << endl;
}
