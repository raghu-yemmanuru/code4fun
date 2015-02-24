#include <iostream>
using namespace std;
struct node {
    int data;
};

int main() {
    string a;
    cin >> a;
    if (a[4] == '\0') {
        cout << "Bingo" << endl;
    }
    cout << a[4] << endl;
}
