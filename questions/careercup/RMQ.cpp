#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <limits>

using namespace std;
typedef vector<int> vi;

void buildRMQ(vi &v, vi &M, int p, int i, int j) {
    if (i > j) {
        return;
    }
    cout << p << " " << i << " " << j << endl;
    if (i == j) {
        M[p] = v[i];
        return;
    }

    int mid = i + (j-i)/2;
    int left = (p << 1) + 1;
    int right = (p << 1) + 2;

    buildRMQ(v,M,left,i,mid);
    buildRMQ(v,M,right,mid+1,j);
    M[p] = min(M[left],M[right]);
    return;
}

int RMQ(vi &M, int i, int j, int p, int beg, int end) {
    if (i <= beg && j >= end) {
        return M[p];
    }
    if (i > end || j < beg) {
        return numeric_limits<int>::max();
    }
    int mid = beg + (end - beg)/2;
    int left = (p << 1) + 1;
    int right = (p << 1) + 2;

    return min(RMQ(M,i,j,left,beg,mid),
               RMQ(M,i,j,right,mid+1,end));
}

int main() {
    vi v;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        v.push_back(rand()%50);
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    vi M(v.size()*2,-1);
    buildRMQ(v,M,0,0,v.size()-1);
    int i,j;
    while (cin >> i >> j) {
        cout << RMQ(M,i,j,0,0,v.size()-1) << endl;
    }
}
