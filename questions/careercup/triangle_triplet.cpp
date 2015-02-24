#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void ncr(vector<int> &v, vector<int> r, int idx, int pos) {
    if (pos == r.size()) {
        copy(r.begin(),r.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }
    for (int i = idx; i < v.size(); i++) {
        r[pos] = v[i];
        ncr(v,r,i+1,pos+1);
    }
}

int main() {
    vector<int> v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    vector<int> r(3,0);

    ncr(v,r,0,0);
}
