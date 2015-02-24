#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;
typedef vector<int> vi;

int main() {
    vi v;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        v.push_back(rand()%5);
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    int i = -1;
    int j;
    for (j = 0; j < v.size(); j++) {
        if (v[j] != 0) {
            swap(v[++i],v[j]);
        }
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
