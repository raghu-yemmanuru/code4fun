#include <iostream>
#include <vector>

using namespace std;

void print(int n, vector<int> &v) {
    if (n == 0) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    for (int i = n; i > 0; i--) {
        if (v.size() && v.back() < i) {
            continue;
        }
        v.push_back(i);
        print(n-i,v);
        v.pop_back();
    }
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    print(n,v);

    return 0;
}
