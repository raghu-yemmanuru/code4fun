#include <iostream>
#include <vector>

using namespace std;

int main () {
    int rows = 5;
    int cols = 5;
    vector<int> row(cols,0);
    vector<vector<int> > arr(rows,row);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
