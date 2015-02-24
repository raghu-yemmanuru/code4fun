#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> vi;

void permute(vi &v, int idx) {
    if (idx == v.size()) {
        copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        swap(v[idx],v[i]);
        permute(v,idx+1);
        swap(v[i],v[idx]);
    }
}

int main() {
    vi v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    permute(v,0);
}
