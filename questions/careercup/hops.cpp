#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;

bool reachable(const vi &v) {
    vb reach(v.size(),false);
    reach[0] = true;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i ; j++) {
            if (reach[j] && (j + v[j] >= i)) {
                reach[i] = true;
            }
        }
    }
    return reach[v.size()-1];

}

int main() {
    vi v;
    int num;
    while(cin >> num) {
        v.push_back(num);
    }
    if (reachable(v)) {
        cout << "Reachable" << endl;
    } else {
        cout << "Sorry" << endl;
    }
}
