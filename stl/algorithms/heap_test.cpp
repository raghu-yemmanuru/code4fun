#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int rand_int() {
    return rand() % 100;
}

int main() {
    vector <int> v(10);

    srand(time(NULL));
    generate(v.begin(), v.end(), rand_int);


    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    make_heap(v.begin(), v.end());
    cout << "After make heap " << v.front() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    pop_heap(v.begin(), v.end());
    //v.pop_back();
    cout << "After pop heap " << v.front() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    push_heap(v.begin(), v.end());
    cout << "After push heap " << v.front() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++) {
        pop_heap(v.begin(), v.end()-i);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;


    return 0;
}
