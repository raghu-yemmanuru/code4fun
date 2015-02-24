#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

int rand_num() {
    return rand()%100;
}

bool b_search(vector<int> &v, int num) {
    int low = 0, high = v.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high)/2;
        if (v[mid] == num) {
            return true;
        }
        if (v[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
        
int low_search(vector<int> &v, int num) {
    int low = 0, high = v.size()-1;
    int mid;
    while (low <= high) {
        mid = (low+high)/2;
        if (v[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (low >= 0 && low < v.size() && v[low] == num) {
        return low;
    }
    return -1;
}

int high_search(vector<int> &v, int num) {
    int low = 0, high = v.size()-1;
    int mid;
    while (low <= high) {
        mid = (low+high)/2;
        if (v[mid] > num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (high >= 0 && high < v.size() && v[high] == num) {
        return high;
    }
    return -1;
}
        


int main() {
    vector<int> v(20,0);
    srand(time(NULL));
    generate(v.begin(),v.end(),rand_num);
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << "[ " << i << "," << v[i] << "] ";
    }
    cout << endl;

    int num;
    while (cin >> num) {
        cout << b_search(v,num) << "  " << low_search(v,num) << "  " << high_search(v,num) << endl;
        //cout << high_search(v,num) << endl;
    }
}
