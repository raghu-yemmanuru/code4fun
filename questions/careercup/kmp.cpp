#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> vi;

void build(const string &P, vi &F) {
    int k = -1;
    F[0] = -1;
    for (int i = 1; i < P.size(); i++) {
        while(k > -1 && P[i] != P[k+1]) {
            k = F[k];
        }
        if (P[i] == P[k+1]) {
            k++;
        }
        F[i] = k;
    }
    return;
}

int main() {
    string T,P;
    while(cin >> T >> P) {
        int n = T.size();
        int m = P.size();
        vi F(m,-1);
        build(P,F);
        int q = -1;
        for (int i = 0; i < T.size(); i++) {
            while(q > -1 && T[i] != P[q+1]) {
                q = F[q];
            }
            if (T[i] == P[q+1]) {
                q++;
            }
            if (q == m-1) {
                cout << "Pattern matched at " << i-m+1 << endl;
                q = -1;
            }
        }
    }
}
