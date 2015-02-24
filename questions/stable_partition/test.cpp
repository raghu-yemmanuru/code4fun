#include <iostream>

using namespace std;

void reverse(int arr[], int beg, int end) {
    int temp;
    while (beg < end) {
        temp = arr[beg];
        arr[beg++] = arr[end];
        arr[end--] = temp;
    }
}

void stable_move(int arr[], int beg, int end) {
    // 1. Reverse the array
    reverse(arr,beg,end);

    // 2. Find the first possitive from beginning 
    //    and first negative from the end
    int p = beg;
    while (p < end && arr[p+1] < 0) {
        p++;
    }

    int q = end;
    while (q > beg && arr[q-1] > 0) {
        q--;
    }

    reverse(arr,beg,p);
    reverse(arr,q,end);

    return;
}

void partition_array(int arr[], int n) {
    int mid = n/2;

    if (n <= 1) {
        return;
    }
    partition_array(arr,mid);
    partition_array(arr+mid, n-mid);
    int p = 0;
    int q = n-1;

    while (p < n && arr[p] < 0) {
        p++;
    }

    while (q >= 0 && arr[q] > 0) {
        q--;
    }

    stable_move(arr,p,q);
}

int main() {
    //int arr[] = {1,7,-5,9,-12,15};
    int arr[] = {3,-2,-5,7,6,8,9,-4,2,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    partition_array(arr,n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
