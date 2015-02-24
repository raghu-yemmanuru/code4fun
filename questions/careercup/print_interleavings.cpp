#include <iostream>
#include <string>
using namespace std;

void printAll(string a, string b, string result) {
    if (!(a.size() || b.size())) {
        cout << result << endl;
        return;
    }

    if (a.size()) {
        printAll(a.substr(1),b,result+a[0]);
    }
    if (b.size()) {
        printAll(a,b.substr(1),result+b[0]);
    }
}

int main() {
    string a,b;
    cin >> a >> b;
    printAll(a,b,"");
}
