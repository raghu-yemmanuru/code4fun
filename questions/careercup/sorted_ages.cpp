#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

int high_search(vi &v, int element) {
    int low = 0, high = v.size()-1;
    int mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if (element < v[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return high;
}

int low_search(vi &v, int element) {
    int low = 0,high = v.size()-1;
    int mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if (element > v[mid]) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return low;
}

void printCounts(vi &v) {
    if (v.size() == 0) {
        return;
    }
    int i = 0;
    int low,high;
    while (i < v.size()) {
        low = low_search(v,v[i]);
        high = high_search(v,v[i]);

        cout << v[i] << ":" << (high-low+1) << endl;
        i = high+1;
    }
}

int main() {
    srand(time(NULL));
    vi v;
    for (int i = 0; i < 30; i++) {
        v.push_back(rand()%6);
    }
    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    printCounts(v);
}
