#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;
typedef vector<int> vi;

void findMinWindow(const string &T, const string &P) {
    vi tobeFound(256,0);
    vi found(256,0);
    for (int i = 0; i < P.size(); i++) {
        tobeFound[P[i]]++;
    }

    int beg = 0,end = 0;
    int count = 0;
    int min_window = INT_MAX;
    int min_beg = -1, min_end = -1;
    for (beg = 0,end = 0; end < T.size(); end++) {
        if (tobeFound[T[end]] == 0) {
            continue;
        }
        found[T[end]]++;
        if (found[T[end]] <= tobeFound[T[end]]) {
            count++;
        }
        if (count == P.size()) {
            while(found[T[beg]] == 0 || found[T[beg]] > tobeFound[T[end]]) {
                if (found[T[beg]] > tobeFound[T[end]]) {
                    found[T[beg]]--;
                }
                beg++;
            }
            if (end-beg+1 < min_window) {
                min_window = end-beg+1;
                min_beg = beg;
                min_end = end;
            }
        }
    }

    if (min_window == INT_MAX) {
        cout << " No window present" << endl;
    } else {
        cout << "Min window present at " << min_beg << " " << min_end << endl;
    }
    return;
}

int main() {
    string T,P;
    cin >> T >> P;
    findMinWindow(T,P);
}
