#include <iostream>
#include <vector>
#include <limits>

using namespace std;
typedef vector<int> vi;

int max_sum_array(vi &v) {
    int max_ending_here;
    int max_sofar;
    
    if (v.size() == 0) {
        return 0;
    }
    
    max_ending_here = max_sofar = v[0];
    
    for (int i = 1; i < v.size(); i++) {
        max_ending_here = max(v[i],max_ending_here + v[i]);
        max_sofar = max(max_sofar, max_ending_here);
    }
    
    return max_sofar;
}

int main() {
    int num;
    vi v;
    while(cin >> num) {
        v.push_back(num);
    }
    cout << max_sum_array(v) << endl;
}
