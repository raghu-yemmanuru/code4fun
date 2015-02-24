#include <iostream>
#include <string>
using namespace std;

void printAscii(char ch) {
    if (ch == 0) {
        return;
    }
    printAscii(ch-1);
    cout << ch << " ";
}

int main() {
    printAscii(127);
    cout << endl;
}
