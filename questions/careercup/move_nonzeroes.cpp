#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>

using namespace std;
typedef vector<int> vi;
int randNumber() {
    return rand()%4;
}

void moveNonZeroes(vi &v) {
    int i = -1;
    for (int j = 0; j < v.size(); j++) {
        if (v[j]) {
            swap(v[++i],v[j]);
        }
    }
    return;
}

int main() {
    vi a(15);
    srand(time(NULL));
    generate(a.begin(),a.end(),randNumber);
    copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    moveNonZeroes(a);
    copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

