#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

struct matrix {
    int a,b,c,d;
    matrix(int _a,int _b, int _c, int _d):a(_a),b(_b),c(_c),d(_d){}
    matrix operator *(const matrix &rhs) {
       int _a = (a*rhs.a + b*rhs.c);
       int _b = (a*rhs.b + b*rhs.d);
       int _c = (c*rhs.a + d*rhs.c);
       int _d = (c*rhs.b + d*rhs.d);
       return matrix(_a,_b,_c,_d);
    }
};

int Feb1(int num) {
    matrix a(1,1,1,0);
    matrix result(1,0,0,1);

    num -= 2;
    while(num) {
        if (num & 1) {
            result = result*a;
        }
        a = a*a;
        num >>= 1;
    }
    return result.a;
}

int Feb(int num) {
    int a = 0, b = 1,c = 1;

    if (num == 1) {
        return 0;
    } else if (num == 2) {
        return 1;
    }

    for (int i = 3; i <= num; i++) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int num;
    while(cin >> num) {
        cout << "Febonacci number is " << Feb(num) << endl;
        cout << "Febonacci number is " << Feb1(num) << endl;
    }
}
