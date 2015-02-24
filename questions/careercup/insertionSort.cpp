#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<int> vi;
int random_number() {
    return rand()%50;
}

void insertionSort(vi &v) {
    int key;
    for (int i = 1; i < v.size(); i++) {
        key = v[i];
        int j = i;
        while(j > 0 && v[j-1] > key) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = key;
    }
}

int main() {
    vi v(20);
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        generate(v.begin(),v.end(),random_number);
        copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        insertionSort(v);
        copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
        cout << endl;
    }
}
