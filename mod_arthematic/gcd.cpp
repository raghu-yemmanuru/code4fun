#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b%a == 0) {
        return a;
    }
    return gcd(b%a,a);
}

int main() {
    int a,b;
    cin >> a >> b;
    if (a > b) {
        swap(a,b);
    }
    cout << gcd(a,b) << endl;
}
