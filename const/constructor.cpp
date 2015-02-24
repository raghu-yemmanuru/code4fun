#include <iostream>
using namespace std;

class ConstructTester {
    public:
    int key;
    ConstructTester ():
        key(1) {}
    void setData (int val) {
        key = val;
        return;
    }

    ConstructTester (const ConstructTester &copy) {
        key = copy.key + 10;
    }

    ConstructTester& operator= (const ConstructTester &rhs) {
        key = rhs.key + 20;
    }
        
};

int main() {
    ConstructTester ct;
    ConstructTester ct1 (ct);
    ConstructTester ct2;

    ct2 = ct1;

    cout << ct.key << endl;
    cout << ct1.key << endl;
    cout << ct2.key << endl;
    return 0;
}
