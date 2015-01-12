#include <iostream>
#include <cmath>
using namespace std;

//explanation:
// d = gcd(a,b); d = a*x + b*y;
// gcd(a,b) = gcd(b%a,a)
// a*x + b*y = (b%a)*x' + a*y'
// a*x + b*y = (b-[b/a]*a)*x' + a*y'
// a*x + b*y = a*(y'-[b/a]*x') + b*x'
// Thus x = (y'-[b/a]*x') and y = x'
int gcd(int a, int b, pair<int,int> &p) {
    int d,x,y;
    if (b%a == 0) {
        p.first = 1;
        p.second = 0;
        return a;
    }

    d = gcd(b%a,a,p);
    x = p.first;
    y = p.second;
    p.second = x;
    p.first = (y-floor(b/a)*x);
    return d;
}

int main() {
    int a,b;
    cin >> a >> b;
    if (a > b) {
        swap(a,b);
    }

    int d;
    pair<int,int> p;
    d = gcd(a,b,p);
    cout << d << " " << p.first << " " << p.second << endl;
}
