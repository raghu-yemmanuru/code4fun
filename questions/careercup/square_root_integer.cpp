#include <iostream>
#include <cmath>

using namespace std;

double squareRootDouble(double num) {
    if (num == 0.0 || num == 1.0) {
        return num;
    }
    if (num < 0) {
        cout << "Negative Numbers!!" << endl;
        return -1.0;
    }
    double low = 0.0, high = num, mid;
    double val;
    while(low <= high) {
        mid = low + (high-low)/2;
        val = mid*mid;
        if (fabs(val-num) < 0.0001) {
            return mid;
        }
        if (val > num) {
            high = mid;
        } else {
            low = mid;
        }
    }
}

int squareRootInt(int num) {
    if (num == 0 || num == 1) {
        return num;
    }
    if (num < 0) {
        cout << "Negative Numbers!!!" << endl;
        return -1;
    }
    int low = 0, high = num;
    int mid;
    unsigned long long midmid,midmid1;
    while(low <= high) {
        mid = low + (high - low)/2;
        midmid = mid*mid;
        midmid1 = (mid+1)*(mid+1);
        if (midmid == num) {
            return mid;
        } else if (midmid > num) {
            high = mid-1;
        } else if (midmid1 > num) {
            return mid;
        } else {
            low = mid+1;
        }
    }
    return low;
}

int main() {
    int num;
    double d;
    while(cin >> d) {
        cout << "Square Root of " << d << " is " << squareRootDouble(d) << endl;
    }
    return 0;
}
