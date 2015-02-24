#include <iostream>

using namespace std;

int intRoot(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    unsigned long long x = 1;
    while (x*x <= n) {
        x++;
    }
    x--;
    return x;
}

int intRoot1(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int low = 1,high = n,mid;
    unsigned long long midmid,midmid1;
    while(low <= high) {
        mid = low + (high-low)/2;
        midmid = mid*mid;
        midmid1 = (mid+1)*(mid+1);
        if (n == midmid) {
            return mid;
        } else if (n < midmid) {
            high = mid-1;
        } else if (n < midmid1) {
            return mid;
        } else {
            low = mid+1;
        }
    }
}

int main() {
    int num;
    cin >> num;
    cout << "Integer Square Root is " << intRoot1(num) << endl;
}
