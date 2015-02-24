#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef vector<int> Vector;
typedef Vector::iterator VecIterator;
typedef reverse_iterator<VecIterator> ReverseVecIterator;

class greater_than:public unary_function<int, bool> {
    public:
    greater_than() {
        cout << "greater_than created " << this << endl;
    }
    bool operator() (const int &rhs) {
        cout << "inside operator " << this << endl;
        return rhs > 3;
    }
};

int main () {
    Vector v;
    //greater_than gt;
    v.reserve(10);
    srand(time(NULL));
    greater_than();

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    random_shuffle(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " ;
    }
    cout << endl;

    // Find the iterator for 5 from the last
    ReverseVecIterator ritr5 = find(v.rend(), v.rbegin(), 5);
    VecIterator itr5 = ritr5.base();

    //remove_if(itr5, v.end(), greater_than());
    //v.erase(remove_if(itr5, v.end(), greater_than), v.end()); 

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " ;
    }
    cout << endl;
    return 0;
}
