#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <iterator>

using namespace std;
typedef vector<int> vi;

int RMQ(vi &M, int p, int b, int e, int i, int j) {
    if (j < b || i > e) {
        return numeric_limits<int>::max();
    }

    if (b >= i && e <= j) {
        return M[p];
    }

    int m = (b+e)/2;
    return min(RMQ(M,2*p,b,m,i,j), RMQ(M,2*p+1,m+1,e,i,j));
}

int build(vi &v, vi &M, int p, int b, int e) {
    if (b > e) {
        return numeric_limits<int>::max();
    } else if (b == e) {
        M[p] = v[b];
        return v[b];
    }

    int m = (b + e)/2;
    M[p] = min(build(v,M,2*p,b, m), build(v,M,2*p+1,m+1,e));
}

    
int main() {
    vi v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand()%100);
    }

    int n = v.size();
    vi M(2*n+1,numeric_limits<int>::max());
    cout << "Min Element is " << build(v,M,1,0,n-1) << endl;

    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    //copy(M.begin(),M.end(),ostream_iterator<int>(cout," "));
    //cout << endl;
    int i,j;
    while(cin >> i >> j) {
        if (i < 0 || i > n-1 || j < 0 || j > n-1 || i > j) {
            cout << "Invalid try again" << endl;
            continue;
        }
        cout << RMQ(M,1,0,n-1,i,j) << endl;
    }
}
