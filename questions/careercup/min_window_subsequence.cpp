#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;
int MAX = 1000;
int main() {
    string x,y;
    cin >> x >> y;
    int m = x.size();
    int n = y.size();

    vvi L(m+1,vi(n+1,0));
    for (int i = 1; i <= n; i++) {
        L[0][i] = MAX;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                L[i][j] = 1 + L[i-1][j-1];
            } else {
                L[i][j] = 1 + L[i-1][j];
            }
        }
    }

    int end_index = -1;
    int min_value = INT_MAX;
    for (int i = 1; i <= m; i++) {
        if (min_value > L[i][n]) {
            min_value = L[i][n];
            end_index = i;
        }
    }

    if (min_value < MAX) {
        cout << "Window may be present at " << end_index << " With length " << min_value << endl;
    } else {
        cout << "I dont think window is present" << endl;
    }
    return 0;
}
