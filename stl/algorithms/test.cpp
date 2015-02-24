#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

int random_int() {
    return rand()%100;
}

using namespace std;

int main() {
    vector <int> v;
    v.reserve(10);

    srand(time(NULL));
    generate(v.begin(), v.begin()+10, random_int);

    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

