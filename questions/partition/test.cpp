#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int random_number() {
    return rand()%100;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(vector<int> &v, int f, int l) {
    int pivot = v[l];
    int i = f-1;

    for (int j = f; j < l; j++) {
        if (v[j] <= pivot) {
            swap(&v[i+1],&v[j]);
            i++;
        }
    }
    swap(&v[i+1],&v[l]);
    return i+1;
}

int main () {
    srand(time(NULL));
    int count = 0;
    cin >> count;
    vector<int> v1(count);
    generate(v1.begin(), v1.end(), random_number);

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "Partitioned at " << partition(v1, 0, v1.size()-1) << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
}
