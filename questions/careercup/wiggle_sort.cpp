#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>

using namespace std;

typedef vector<int> vi;

int main() {
    srand(time(NULL));
    vi v;
    for (int i = 0; i < 20; i++) {
        v.push_back(rand()%50);
    }

    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    for (int i = 0; i < 19; i++) {
        if (i&1) {
            if (v[i] < v[i+1]) {
                swap(v[i],v[i+1]);
            }
        } else if (v[i] > v[i+1]) {
            swap(v[i],v[i+1]);
        }
    }

    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    for (int i = 0; i < 19; i++) {
        if (i&1) {
            if (v[i] < v[i+1]) {
                cout << "ERRORED" << endl;
            }
        } else if (v[i] > v[i+1]) {
            cout << "ERRORED" << endl;
        }
    }
}


