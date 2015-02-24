#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;
typedef vector<int> vi;
int random_number() {
    return rand()%20;
}

void buildRMQ(const vi &v, vi &M, int beg, int end, int pos) {
    if (beg == end) {
        M[pos] = beg;
        return;
    }
    int left = (pos << 1) + 1;
    int right = (pos << 1) + 2;
    int mid = beg + (end-beg)/2;
    buildRMQ(v,M,beg,mid,left);
    buildRMQ(v,M,mid+1,end,right);
    if (v[M[left]] < v[M[right]]) {
        M[pos] = M[left];
    } else {
        M[pos] = M[right];
    }
    return;
}

int RMQ(const vi &M, const vi &v, int beg, int end, int i, int j, int pos) {
    if (i > end || j < beg) {
        return -1;
    }
    if (i <= beg && j >= end) {
        return M[pos];
    }
    int mid = beg + (end-beg)/2;
    int left = RMQ(M,v,beg,mid,i,j,(pos << 1) + 1);
    int right = RMQ(M,v,mid+1,end,i,j,(pos << 1) + 2);

    if (left == -1) {
        return right;
    } else if (right == -1) {
        return left;
    } else if (v[left] < v[right]) {
        return left;
    } else {
        return right;
    }
}

int maxArea(const vi &M, const vi &v, int beg, int end) {
    if (beg > end) {
        return numeric_limits<int>::min();
    }

    if (beg == end) {
        return v[beg];
    }
    int n = v.size()-1;
    //cout << "BEG " << beg << " " << end << endl;

    int minIdx = RMQ(M,v,0,n,beg,end,0);
    cout << "Min value is " << v[minIdx] << endl;
    int val = max(max(maxArea(M,v,beg,minIdx-1), maxArea(M,v,minIdx+1,end)),
                v[minIdx]*(end-beg+1));
    cout << beg << " " << end << "Value is " << val << endl;
    return val;
}

int main() {
    /*vi v(10);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_number);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;*/
    int num;
    vi v;
    v.push_back(6);
    v.push_back(2);
    v.push_back(5);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(6);
    //6 2 5 4 5 1 6
    /*while(cin >> num) {
        v.push_back(num);
    }*/
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    vi M(3*v.size(),-1);
    buildRMQ(v,M,0,v.size()-1,0);
    int i,j;
    /*while(cin >> i >> j) {
        cout << RMQ(M,v,0,v.size()-1,i,j,0) << endl;
    }*/

    cout << "Max Area is " << maxArea(M,v,0,v.size()-1) << endl;
}
