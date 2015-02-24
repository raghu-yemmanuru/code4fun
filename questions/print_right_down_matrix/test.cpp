#include <iostream>
#include <vector>

using namespace std;
void printMatrix(int **arr, int i, int j, int m, int n, vector<int> &path) {
    //cout << i << " " << j << " " << m << " " << n << endl;
    if (i > m || j > n || i < 0 || j < 0) {
        return;
    }
    path.push_back(arr[i][j]);
    if (i == m && j == n) {
        cout << "PATH ";
        for (int r = 0; r < m+n+1; r++) {
            cout << path[r] << " ";
        }
        cout << endl;
        return;
    }
    //Go right
    if (j < n) {
        printMatrix(arr, i, j+1, m, n, path);
        path.pop_back();
    }
    //Go down
    if (i < m) {
        printMatrix(arr, i+1, j, m, n, path);
        path.pop_back();
    }
    return;
}

int main() {
    int rows,cols;
    int count = 0;
    cin >> rows;
    cin >> cols;

    int **arr;
    arr = new int*[rows];

    for (int i = 0; i < rows;i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = ++count;
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    vector<int> path;
    path.reserve(rows+cols-1);
    printMatrix(arr, 0, 0, rows-1,cols-1, path);
}
