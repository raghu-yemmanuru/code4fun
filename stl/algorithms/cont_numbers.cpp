#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    vector <int> v;

    int count = 0;
    int num;
    srand(time(NULL));
    make_heap(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < 5; i++) {
        num = rand() % 1000;
        cout << num << endl;
        v.push_back(num);
        push_heap(v.begin(),v.end(), greater<int>());
    }

    for (int i = 0; i < 30; i++) {
        num = rand() % 1000;
        cout << num << endl;
        if (num > v.front()) {
            pop_heap(v.begin(), v.end(), greater<int>());
            v.pop_back();
            v.push_back(num);
            push_heap(v.begin(), v.end(),greater<int>());
        }
    }

    cout << endl;
    cout << "Top 5 elements " << v.size() << " " << endl;
    sort_heap(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < 5; i++) {
        cout << v[i] << endl;
    }
}
