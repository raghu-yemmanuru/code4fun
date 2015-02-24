#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

void printPaths(vvi &A, int x, int y, vi &path) {
    if (x >= A.size() || y >= A[x].size()) {
        return;
    }

    path.push_back(A[x][y]);
    if (x == A.size()-1 && y == A[x].size()-1) {
        copy(path.begin(), path.end(), ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }

    if (y < A[x].size()-1) {
        printPaths(A,x,y+1,path);
        path.pop_back();
    }

    if (x < A.size()-1) {
        printPaths(A,x+1,y,path);
        path.pop_back();
    }

    return;
}

int main() {
    int r,c;
    cin >> r >> c;
    vvi A(r,vi(c,0));
    int val = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            A[i][j] = ++val;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    vi path;
    printPaths(A,0,0,path);
}
