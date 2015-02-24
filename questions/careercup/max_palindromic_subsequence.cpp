#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

int main() {
    vector<int> v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    int n = v.size();
    
    vvi L(n+1,vi(n+1,0));

    for (int i = 1; i <= n; i++) {
        L[i][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if(v[i-1] == v[i]) {
            L[i][i+1] = 2;
        } else {
                L[i][i+1] = 1;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 1; i <= n-len+1; i++) {
            int j = i+len-1;
            if (v[i-1] == v[j-1]) {
                L[i][j] = 2 + L[i+1][j-1];
            } else {
                L[i][j] = max(L[i][j-1], L[i+1][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << L[i][j] << "\t";
        }
        cout << endl;
    }

    cout << L[1][n] << endl;
}
