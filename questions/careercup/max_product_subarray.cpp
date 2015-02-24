#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int> vi;

int threeway_min(int i, int j, int k) {
    int temp = numeric_limits<int>::max();
    temp = min(temp,i);
    temp = min(temp,j);
    temp = min(temp,k);
    
    return temp;
}

int threeway_max(int i, int j, int k) {
    int temp = numeric_limits<int>::min();
    temp = max(temp,i);
    temp = max(temp,j);
    temp = max(temp,k);
    
    return temp;
}

int max_product(vi &v) {
    int max_ending_before;
    int min_ending_before;
    int max_sofar;
    if (v.size() == 0) {
        return 0;
    }
    
    max_ending_before = min_ending_before = max_sofar = v[0];
    
    for (int i = 1; i < v.size(); i++) {
        int min_ending_here = threeway_min(max_ending_before * v[i], v[i], min_ending_before * v[i]);
        int max_ending_here = threeway_max(v[i], min_ending_before *v[i], max_ending_before * v[i]);
        max_sofar = max(max_sofar,max_ending_here);
        min_ending_before = min_ending_here;
        max_ending_before = max_ending_here;
    }
    
    return max_sofar;
}

int main() {
    int num;
    vi v;
    while(cin >> num) {
        v.push_back(num);
    }
    cout << max_product(v) << endl;
}
