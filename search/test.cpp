#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int b_search(vector<int> &v, int key) {
    int low = 0;
    int high = v.size()-1;
    int mid;
    while(low <= high) {
        mid = (low + high)/2;
        if (key == v[mid]) {
            return mid;
        } else if (key < v[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

int b_search_min(vector<int> &v, int key) {
    int low,high,mid;
    low = 0;
    high = v.size()-1;
    if (key < v[low] || key > v[high]) {
        return -1;
    }
    while (low <= high) {
        mid = (low + high)/2;
        if (key > v[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int b_search_max(vector<int> &v, int key) {
    int low,high,mid;
    low = 0,high = v.size()-1;
    if (key < v[low] || key > v[high]) {
        return -1;
    }
    while (low <= high) {
        mid = (low + high)/2;
        if (key < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int main() {
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i <= 10; i++) {
        v.push_back(i*10);
    }
    v.push_back(40);
    v.push_back(40);
    v.push_back(40);
    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    cout << v.size() << endl;
    cout << b_search(v,4) << endl;
    cout << b_search_min(v,55) << endl;
    cout << b_search_min(v,5) << endl;
    cout << b_search_max(v,55) << endl;
    cout << b_search_min(v,100) << endl;
    cout << b_search_max(v,100) << endl;
    /*cout << b_search_min(v,100) << endl;
    cout << b_search_max(v,100) << endl;
    cout << b_search_min(v,-100) << endl;
    cout << b_search_max(v,-100) << endl;*/
}
