#include <iostream>
using namespace std;

inline int min(int a, int b) {
    return (a<b?a:b);
}
int kthsmallest(int *a, int m, int *b, int n, int k) {
    if (m > n) {
        return kthsmallest(b, n, a, m, k);
    }

    m = min(m, k);
    n = min(n, k);
    int s = 0;
    int f = m;
    int i,j;
    while (s < f) {
        i = s + (f - s)/2;
        j = k - 1 - i;

        if (j >= n || a[i] < b[j]) {
            s = i+1;
        } else {
            f = i;
        }
    }

    int pot_a = INT_MIN;
    int pot_b = INT_MIN;
    if (s > 0) {
        pot_a = a[s-1];
    }
    if (k-s-1 >= 0) {
        pot_b = b[k-s-1];
    }

    return max(pot_a,pot_b);
}

int main () {
    int a[] = {2,5};
    int b[] = {1,3,7,9};

    cout << kthsmallest(a,2,b,4,1) << endl;
    cout << kthsmallest(a,2,b,4,2) << endl;
    cout << kthsmallest(a,2,b,4,3) << endl;
    cout << kthsmallest(a,2,b,4,4) << endl;
    cout << kthsmallest(a,2,b,4,5) << endl;
    cout << kthsmallest(a,2,b,4,6) << endl;
    return 0;
}


