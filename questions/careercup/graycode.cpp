#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<string> vs;


void gray(int n, vs &v) {
    v.clear();
    v.push_back("0");
    v.push_back("1");
    for (int i = 2; i <= n; i++) {
        int k = v.size();
        for (int j = k-1; j >= 0; j--) {
            v.push_back(v[j]);
        }
        for (int j = 0; j < k; j++) {
            v[j] = "0" + v[j];
        }
        for (int j = k; j < v.size(); j++) {
            v[j] = "1" + v[j];
        }
    }
    return;
}

int main() {
    int num;
    vs v;
    while(cin >> num) {
        gray(num,v);
        copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
        cout << endl;
    }
}
