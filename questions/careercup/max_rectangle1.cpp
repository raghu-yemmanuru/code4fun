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
            if (A[i-1][j-1] == 1) {
                T[i][j] = T[i-1][j] + 1;
            }
        }
    }

    /*for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }*/

    int max_area = numeric_limits<int>::min();
    int area,height;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            height = T[i][j];
            for (int k = j; k > 0; k--) {
                height = min(height,T[i][k]);
                if (height == 0) {
                    break;
                }
                area = height * (j-k+1);
                if (area > max_area) {
                    cout << max_area << "at " << i << " " << j << " " << k << endl;
                    max_area = area;
                }
            }
        }
    }

    cout << max_area << endl;
                    
}
