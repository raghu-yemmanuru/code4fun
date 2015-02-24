#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
void buildArray (int **arr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = 100 + (rand() % 900);
        }
        sort(arr[i], arr[i] + 10);
    }

   vector <int> vec;
   vec.reserve(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            vec.push_back(arr[j][i]);
        }
        sort(vec.begin(),vec.end());
        for (int j = 0; j < 10; j++) {
            arr[j][i] = vec[j];
        }
        vec.clear();
    }
    return;
}

void find (int **arr, int value) {
    bool valueFound = false;
    int row = 9;
    int col = 0;
    while (!valueFound) {
        if (row < 0 || col < 0 || row > 9 || col > 9) {
            valueFound = false;
            break;
        }

        int curVal = arr[row][col];
        if (curVal == value) {
            valueFound = true;
            break;
        }

        if (curVal < value) {
           col++;
        } else {
            row--;
        }
    }

    if (valueFound) {
        cout << "value found at " << row << " " << col << endl;
    } else {
        cout << "Value is missing " << endl;
    }
}

int main () {
    int **arr;
    srand(time(NULL));
    try {
        arr = new int*[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = new int[10];
        }
    } catch (exception &ex) {
        cout << "Exception " << ex.what() << endl;
    }

    buildArray(arr);
    find (arr, 300);//arr[5][3]);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
