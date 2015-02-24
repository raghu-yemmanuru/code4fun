#include <iostream>

using namespace std;
int main() {
    int arr [] = {9,9,9};//,4,2,2,4,6,9};
    int length = sizeof(arr)/sizeof(int);

    int i = length/2 - 1;
    int j = length/2 + length%2;
    bool leftSmaller = false;
    int count_9 = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] == 9) {
            count_9++;
        }
    }
    if (count_9 == length) {
        cout << 1 << " ";
        for (int i = 0; i < length; i++) {
            cout << 0 << " ";
        }
        cout << 1 << endl;
        return 0;
    }

    while (i >= 0 && arr[j] >= arr[i]) {
        arr[j] = arr[i];
        j++;
        i--;
    }

    if (i < 0 || arr[i] < arr[j]) {
        leftSmaller = true;
    }

    while (i >= 0) {
        arr[j] = arr[i];
        j++;
        i--;
    }

    int carry = 0;
    if (leftSmaller) {
        if (length % 2) {
            arr[length/2] += 1;
            carry = arr[length/2]/10;
            arr[length/2] = arr[length/2]%10;
        } else {
            carry = 1;
        }

        i = length/2 - 1;
        j = length/2 + length%2;
    }

    while (i >= 0) {
        arr[i] += carry;
        carry = arr[i]/10;
        arr[i] = arr[i]%10;
        arr[j] = arr[i];
        i--;
        j++;
    }

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}




