#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    unsigned long long a,b;
    cin >> a >> b;
    unsigned long long result = 1;
    while(b) {
        if (b & 1) {
            result *= a;
        }
        a *= a;
        b >>= 1;
    }

    cout << result << endl;
}
