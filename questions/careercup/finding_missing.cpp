#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>

using namespace std;

int basecase(vector<int> &v, int low, int high) {
    for (int i = low; i < high; i++) {
        if (v[i+1]-v[i] > 1) {
            return v[i+1]-1;
        }
    }
    return -1;
}

int missing(vector<int> &v) {
    int low = 0;
    int high = v.size() -1;
    int mid;

    while (low <= high) {
        if (high-low+1 <= 2) {
            return basecase(v,low,high);
        }
        mid = low + (high-low)/2;
        if (mid-low < v[mid]-v[low]) {
            high = mid;
        } else {
            low = mid;
        }
    }
}

int missing2(vector<int> &v) {
    int low = 0,high = v.size()-1,mid;
    if (v.size() == 0 || v.size() == -1) {
        //cout << "No missing Elements" << endl;
        return -1;
    }
    while (low <= high) {
        if (high-low == 1) {
            if (v[low] == v[high]-2) {
                return v[high]-1;
            } else {
                //cout << "Invalid input" << endl;
                return -1;
            }
        }
        mid = low + (high-low)/2;
        if (mid-low < v[mid]-v[low]) {
            high = mid;
        } else {
            low = mid;
        }
    }
}

int main() {
    int num;
    vector<int> v;
    srand(time(NULL));
    int n = rand()%10;
    int miss = rand()%n;
    for (int i = 0; i < n; i++) {
        if (i == miss) {
            continue;
        }
        v.push_back(100+i);
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    cout << "Missing number " << missing2(v) << endl;
    cout << "Missing number " << missing(v) << endl;
}
