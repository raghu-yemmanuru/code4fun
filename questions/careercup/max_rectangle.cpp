#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

int main() {
    int r,c;
    ifstream ifs("input_rectangle");
    ifs >> r >> c;
    vvi A(r,vi(c,0));
    vvi T(r+1,vi(c+1,0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ifs >> A[i][j];
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int val = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            T[i][j] = T[i-1][j] + T[i][j-1] - T[i-1][j-1] + (A[i-1][j-1] == 0 ? 1 : 0);
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }

    int max_area = numeric_limits<int>::min();
    int no_zeroes,area;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int k = i; k <= r; k++) {
                for (int l = j; l <= c; l++) {
                    no_zeroes = T[k][l] - T[i-1][l] - T[k][j-1] + T[i-1][j-1];
                    area = (k-i+1)*(l-j+1);
                    if (!no_zeroes && area > max_area) {
                        max_area = area;
                        cout << max_area << " " << i << " " << j << " " << k << " " << l << endl;
                    }
                }
            }
        }
    }

    cout << max_area << endl;
                    
}
