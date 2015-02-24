#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string LCS (string &x, string &y) {
    int m = x.size();
    int n = y.size();

    int L[m+1][n+1];
    int S[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            L[i][j] = S[i][j] = 0;
        }
    }

    int max = INT_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                L[i][j] = 1 + L[i-1][j-1];
                S[i][j] = 1;
            }
            else if (L[i-1][j] > L[i][j-1]) {
                L[i][j] = L[i-1][j];
                S[i][j] = 2;
            } else {
                L[i][j] = L[i][j-1];
                S[i][j] = 3;
            }
            if (L[i][j] > max) {
                max = L[i][j];
            }
            //cout << S[i][j] << " ";
            //cout << L[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << max << endl;

    int i = m;
    int j = n;
    string result;
    while (i > 0 && j > 0) {
        if (S[i][j] == 1) {
            result.push_back(x[i-1]);
            i = i-1;
            j = j-1;
        } else if (S[i][j] == 2) {
            i = i-1;
        } else {
            j = j-1;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main () {
    string x = "BANANA";//"ABCDEFG";
    string y = "ATANA";//"BCDGK";

    cout << LCS (x,y) << endl;
}

