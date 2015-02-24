#include <iostream>
#include <cmath>
using namespace std;

double myroot(double d) {
    double low = 0, high = d;
    double mid;
    if (d == 0.0 || d == 1.0) {
        return d;
    }
    while (low <= high) {
        mid = (low+high)/2;
        double val = mid*mid;
        if (fabs(val - d) <= 0.00001) {
            break;
        }
        if (val > d) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return mid;
}

int main() {
    double d;
    cin >> d;
    cout << "Square Root " << myroot(d) << endl;
}
