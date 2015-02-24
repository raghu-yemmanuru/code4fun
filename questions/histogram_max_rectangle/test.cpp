#include <iostream>
#include <stack>
#include <vector>

using namespace std;

inline int max(int a,int b) {
    return (a>b ? a : b);
}

// Always maintain non decreasing stack
// When the new value is less than top, pop the stack and calculate area with the top
int getMaxArea(vector<int> &h) {
    int max_area = 0;
    stack<int> s;
    int count = 0;

    for (int i = 0; i < h.size(); i++) {
        if (s.empty() || h[i] >= s.top()) {
            s.push(h[i]);
        } else {
            count = 0;
            while (!s.empty() && h[i] < s.top()) {
                ++count;
                int area_with_top = s.top()*count;
                max_area = max(max_area, area_with_top);
                s.pop();
            }
            for (int j = 0; j < count+1; j++) {
                s.push(h[i]);
            }
        }
    }
    count = 0;
    while(!s.empty()) {
        ++count;
        int area_with_top = s.top()*count;
        max_area = max(max_area, area_with_top);
        s.pop();
    }

    return max_area;
}

int main() {
    int arr[] = {1,2,3,4,5};
    //int arr[] = {15, 15, 12, 16, 0, 17, 4, 7, 10, 7};
    vector<int> v(arr, arr+(sizeof(arr)/sizeof(int)));

    cout << getMaxArea(v) << endl;
}
