#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

struct Transform {
    int operator()(int val) {
        return val + 1;
    }
};

int main() {
    vector <int> v;
    v.reserve(20);
    for (int i = 0; i < 20; i++) {
        v.push_back(rand()%1000);
    }

    copy (v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;

    Transform d;
    transform(v.begin(), v.end(), ostream_iterator<int>(cout," "),d);
    cout << endl;

    //transform(v.begin(), v.end(), v.begin(), d);
    copy (v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    return 0;
}
