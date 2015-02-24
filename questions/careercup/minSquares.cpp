#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<int> vi;

int  minSquares(int n) {
    vi M(n+1,numeric_limits<int>::max());
    M[0] = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= sqrt(j); i++) {
            M[j] = min(M[j],1+M[j-i*i]);
        }
    }
    return M[n];
}

int main() {
    int num;
    while (cin >> num) {
        int r = minSquares(num);
        cout << r << endl;
        //copy(r.begin(),r.end(),ostream_iterator<int>(cout," "));
        //cout << endl;
    }
}
