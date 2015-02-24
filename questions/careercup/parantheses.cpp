#include <iostream>
#include <string>

using namespace std;
void permute(string s, int left, int right, int n) {
    if (right > left || left+right > n || left > n/2 || right > n/2) {
        return;
    }
    if (left + right == n && left == right) {
        cout << s << endl;
        return;
    }
    permute(s+'(',left+1,right,n);
    permute(s+')',left,right+1,n);
}

void printBrackets(int n) {
    string result = "";
    permute(result,0,0,2*n);
}

int main () {
    int num;
    cin >> num;
    printBrackets(num);
}
