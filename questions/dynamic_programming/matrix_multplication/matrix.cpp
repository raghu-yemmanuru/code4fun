#include <iostream>
#include <vector>
#include <iterator>
#include <limits>

// M[i][j] is the min multiplication operations in [i,j] interval
// M[i][j] = Min { M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j] }
//          i<=k<j

using namespace std;
int main() {
    vector<int> p;
    vector<vector<int> > M;

    int val;
    while(cin >> val) {
        p.push_back(val);
    }
    int N = p.size() - 1;
    M.assign(N+1,vector<int>(N+1,0));

    int i,j,k,len;

    for (len = 2; len <= N; len++) {
        for (int i = 1; i <= N-len+1; i++) {
            j = i+len-1;
            int min = numeric_limits<int>::max();
            for (int k = i; k < j; k++) {
                val = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
                if (min > val) {
                    min = val;
                }
            }
            M[i][j] = min;
        }
    }
    cout << M[1][N] << endl;
}

