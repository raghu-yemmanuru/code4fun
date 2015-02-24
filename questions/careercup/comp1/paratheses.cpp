#include <iostream>
#include <string>

using namespace std;

void generate(int left,int right, int n, string result) {
    if (left < right || left+right > 2*n || left > n || right > n) {
        return;
    }
    if (left == n && right == n) {
        cout << result << endl;
        return;
    }
    generate(left+1,right,n,result+"(");
    generate(left,right+1,n,result+")");
}

int main () {
    int num;
    cin >> num;
    generate(0,0,num,"");
}
