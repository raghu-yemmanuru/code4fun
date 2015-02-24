#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
int findMin1(const vi &v) {
    int low = 0, high = v.size()-1;
    int mid;
    while(v[low] > v[high]) {
        mid = low + (high-low)/2;
        if (v[mid] > v[high]) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    return v[low];
}
        
int findMin2(const vi &v) {
    int low = 0, high = v.size()-1;
    int mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if (low == high || low+1 == high) {
            return min(v[low],v[high]);
        } else if (v[mid] >= v[high]) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return -1;
}

int findMin(const vi &v) {
    int low = 0, high = v.size()-1;
    int mid;
    while(low <= high) {
        if (low == high || low+1 == high) {
            return min(v[low],v[high]);
        }
        mid = low + (high-low)/2;
        if (v[mid] >= v[low]) {
            if (v[mid] <= v[high]) {
                high = mid;
            } else {
                low = mid;
            }
        } else {
            high = mid;
        }
    }
}

int main() {
    vi v;
    int num;
    srand(time(NULL));
    vi t1,t2;
    for (int i = 0; i < 10; i++) {
        t1.push_back(rand()%20);
    }
    sort(t1.begin(),t1.end());
    int idx = rand()%10;
    copy(t1.begin()+idx,t1.end(),back_inserter(v));
    copy(t1.begin(),t1.begin()+idx,back_inserter(v));
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    cout << findMin(v) << endl;
    cout << findMin1(v) << endl;
    cout << findMin2(v) << endl;
}
