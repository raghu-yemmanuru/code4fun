#include <iostream>

using namespace std;

int match(int x[], int y[], int count) {
    for (int i = 0; i < count; i++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

void clearArray(int x[], int num) {
    for (int i = 0; i < num; i++) {
        x[i] = 0;
    }
}
        
int main() {
    string T,P;
    cin >> T >> P;
    int n,m;
    n = T.size();
    m = P.size();
    int pcount[256] = {0};
    int wcount[256] = {0};
    for (int i = 0; i < m; i++) {
        pcount[P[i]]++;
        wcount[T[i]]++;
    }
    if (match(pcount,wcount,256)) {
        cout << "Matched at 0" << endl;
    }

    //clearArray(wcount);
    for (int i = m; i < T.size(); i++) {
        wcount[T[i]]++;
        wcount[T[i-m]]--;
        if (pcount[T[i]] != wcount[T[i]] || pcount[T[i-m]] != wcount[T[i-m]])
            continue;
        if (match (pcount,wcount,256)) {
            cout << "Matched at " << i-m+1 << endl;
            return 0;
        }
    }
        
    cout << "Could not find... " << endl;
}
