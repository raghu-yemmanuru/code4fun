#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double num;
    cin >> num;
    long root = sqrt(num);
    long i = 0, j = root;
    long val = 0;
    while (i <= j) {
        val = (i*i)+(j*j);
        if (val == num) {
            cout << i << " " << j << endl;
            i++; j--;
        } else if (val < num) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}
    
