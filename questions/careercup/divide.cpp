#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> Pair;

Pair divide(int a,int b) {
    int low = 1;
    int high = a;
    int mid;
    int val,val1;
    while(low <= high) {
        mid = low + (high-low)/2;
        val = (mid*b);
        if (val == a) {
            return make_pair(mid,0);
        } else if (val < a) {
            low = mid+1;
        } else {
            val1 = (mid-1)*b;
            if (val1 < a) {
                return make_pair(mid-1,a-(b*(mid-1)));
            } else {
                high = mid-1;
            }
        }
    }
    cout << "Not able to find division" << endl;
    return make_pair(0,-1);
}

int main() {
    int a,b;
    cin >> a >> b;
    Pair p = divide(a,b);
    cout << "Quotient is " << p.first << endl;
    cout << "remainder is " << p.second << endl;
}
