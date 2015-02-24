#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void printFactors(int n, int max, string result) {
    for (int i = n/2; i >= 2; i--) {
        if (n%i == 0) {
            if (i >= n/i && i <= max && n/i <= max) {
                cout << result << i << " * " << n/i << endl;
            }
            if (i <= max) {
                stringstream ss;
                ss << i << " * ";
                printFactors(n/i,i,result+ss.str());
            }
        }
    }
}

int main() {
    int num;
    while (cin >> num) {
        cout << num << " * " << 1 << endl;
        printFactors(num,num,"");
    }
}
