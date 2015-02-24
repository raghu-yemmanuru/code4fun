#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int findIndex(const vi &v, int val) {
    int low = 0, high = v.size()-1, mid;
    while(low <= high) {
        mid = low + (high - low)/2;
        if (v[mid] == val) {
            return mid;
        }
        if (v[mid] >= v[low]) {
            if (val >= v[low] && val < v[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        } else {
            if (val > v[mid] && val <= v[high]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    int num;
    vi v;
    int val;
    cin >> val;
    while(cin >> num) {
        v.push_back(num);
    }
    cout << findIndex(v,val) << endl;
}
    
