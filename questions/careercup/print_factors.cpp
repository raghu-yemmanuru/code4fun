#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printFactors(int num, string result, int maxVal) {
    for (int i = num/2; i >= 2; i--) {
        if (num %i == 0) {
            if (i >= num/i && i <= maxVal && num/i <= maxVal) {
                cout << result << i << " * " << num/i << endl;
            }
            if (i <= maxVal) {
                stringstream ss;
                ss << i << " * ";
                printFactors(num/i, result + ss.str(), i);
            }
        }
    }
}

int main() {
    int num;
    while (cin >> num) {
        cout << num << " * " << 1 << endl;
        printFactors(num,"",num);
    }
}
