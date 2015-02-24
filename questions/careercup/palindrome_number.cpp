#include <iostream>
using namespace std;

int palindrome(int n) {
    int div = 1;
    while (n/div >= 10) {
        div *= 10;
    }
    while (n) {
        int l = n/div;
        int r = n%10;
        if (l != r) {
            return false;
        }
        n = (n%div)/10;
        /*n = n-(l*div);
        n = n/10;*/
        div = div/100;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (palindrome(n)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
