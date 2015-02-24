#include <iostream>

using namespace std;

unsigned long superPow(unsigned long a, int b) {
    unsigned long result = 1;
    while(b) {
        if (b&1) {
            result *= a;
        }
        b >>= 1;
        a *= a;
    }
    return result;
}

int main() {
    int a,b;
    while(cin >> a >> b) {
        cout << superPow(a,b) << endl;
    }
}
