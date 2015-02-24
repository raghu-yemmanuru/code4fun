#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
void printIntersection (vi &a, vi &b) {
    vi c;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;
}

int main() {
    vi a,b;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        a.push_back(rand()%20);
        b.push_back(rand()%20);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    copy(b.begin(),b.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    printIntersection(a,b);
}

