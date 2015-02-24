#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Factor(string output, int num, int max) {
    int q;
    for (int i = num-1; i >= 2; i--) {
        if (num%i == 0) {
            q = num/i;
            stringstream ss;
            // print as long as the numbers are non increasing and <= max
            if (i >= q && i <= max && q <= max) {
                ss << output << i << " * " << q << " ";
                cout << ss.str() << endl;
                ss.str("");
            }
            // Proceed further in the chain only if new value is going to be smaller
            if (i <= max) {
                ss << i << " * ";
                Factor(output + ss.str(), q, i);
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    string output("");
    cout << num << " * " << 1 << endl;
    Factor(output,num,num);
}
