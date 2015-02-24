#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;
int main() {
    int m,n;
    cin >> m >> n;
    vi x(m,0),y(n,0);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
        
    vvi L(m+1,vi(n+1,0));
    for (int i = 1; i <= n; i++) {
        L[0][i] = INT_MAX;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                if (L[i-1][j-1] == INT_MAX) {
                    L[i][j] = INT_MAX;
                } else {
                    L[i][j] = 1 + L[i-1][j-1];
                }
            } else {
                if (L[i-1][j] == INT_MAX) {
                    L[i][j] = INT_MAX;
                } else {
                    L[i][j] = 1 + L[i-1][j];
                }
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

    if (min_value < INT_MAX) {
        cout << "Window may be present at " << end_index << " With length " << min_value << endl;
    } else {
        cout << "I dont think window is present" << endl;
    }
    return 0;
}
