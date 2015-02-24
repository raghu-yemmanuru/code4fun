#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;

void printPrimes(int num) {
    vb v(num+1,true);
    for (int i = 2; i <= sqrt(num); i++) {
        for (int j = i*i; j <= num; j += i) {
            v[j] = false;
        }
    }
    for (int i = 2; i <= num; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    printPrimes(num);
}
