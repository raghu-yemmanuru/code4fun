#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
using namespace std;

int random_numer() {
    return rand()%100;
}


void partition(vector<int> &v) {
    int i = -1;
    int j;
    int pivot = v[v.size()-1];
    for (j = 0; j < v.size()-1; j++) {
        if (v[j] <= pivot) {
            swap(v[i+1],v[j]);
            i++;
        }
    }
    cout << "partitioned till " << i << endl;
    swap(v[i+1],v[j]);
}

int main() {
    vector<int> v(10,0);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_numer);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    cout << "Partitioning based on " << v[v.size()-1] << endl;
    partition(v);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

