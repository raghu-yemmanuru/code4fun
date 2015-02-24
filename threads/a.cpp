#include <thread>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> vi;

void mergeSort(vi *p_v) {
    vi &v = *p_v;
    if (v[0] > v[1]) {
        swap(v[0],v[1]);
        return;
    }
    return;
}

int main() {
    int i = 0;
    vi v;
    v.push_back(5);
    v.push_back(3);
    thread t(mergeSort, &v);
    t.join();
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
