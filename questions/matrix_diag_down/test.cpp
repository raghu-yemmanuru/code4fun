#include <iostream>
using namespace std;

void build_array (int **arr, int rows, int cols) {
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = count++;
        }
    }
}

void print_array(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void print_diag_down(int **arr, int r, int c, int k) {
    for (int i = 0; i < k; i++) {
        cout << arr[r+i][c-i] << " ";
    }
    cout << endl;
}

int main () {
    const int rows = 4;
    const int cols = 4;
    int **arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    build_array(arr,rows,cols);
    print_array(arr,4,4);
    int count = 0;
    for (int i = 0; i < cols; i++) {
        print_diag_down(arr,0,i,++count);
    }

    for (int i = 1; i < rows; i++) {
        print_diag_down(arr,i,cols-1,--count);
    }
    return 0;
}
