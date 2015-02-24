#include <iostream>
#include <limits>

using namespace std;

int main() {
    string T,P;
    cin >> T >> P;
    int n = T.size();
    int m = P.size();
    int w[256] = {0};
    int p[256] = {0};
    for (int i = 0; i < m; i++) {
        p[P[i]]++;
    }

    int count = 0;
    int min_window = numeric_limits<int>::max();
    int pos = -1;
    for (int beg = 0, end = 0; end < n; end++) {
        // uninteresting characters
        if (p[T[end]] == 0)
            continue;

        // potential character
        if (p[T[end]] > w[T[end]]) {
            count++;
        }
        w[T[end]]++; // Update Window Critical

        // See if window has full pattern
        if (count == m) {
            // Try to shrink it if we can
            while (w[T[beg]] > p[T[beg]] || w[T[beg]] == 0) {
                if (w[T[beg]] > p[T[beg]]) {
                    w[T[beg]]--;    // Update window critical
                }
                beg++;
            }
            min_window = min(min_window,end-beg+1);
            pos = beg;
        }
    }
    if (pos != -1) {
        cout << "Min Window at " << pos << "," << pos+count-1 << endl;
    } else {
        cout << "Sorry No window" << endl;
    }
}

