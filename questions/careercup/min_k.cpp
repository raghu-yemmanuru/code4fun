#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <set>

using namespace std;
typedef vector<int> vi;

bool sumPossible(const vi &v, int num) {
    set<int> s;
    for (int i = 0; i < v.size(); i++) {
        if (s.count(num-v[i])) {
            cout << num-v[i] << " " << v[i] << endl;
        }
        s.insert(v[i]);
    }
}

int random_number() {
    return rand()%100;
}

int main() {
    vi v(20);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_number);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    int num;
    while(cin >> num) {
        sumPossible(v,num);
    }
    return 0;
}
