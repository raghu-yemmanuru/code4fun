#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Widget {
    public:
        int id;
        Widget (int _id) : id(_id) {}
        int getId () {
            return id;
        }
};

class binary_functor {
    public:
        int m_x;
        binary_functor(int x = 0):m_x(x) {
            cout << "constructed binary functor " << m_x << " " << this << endl;
        }
        bool operator () (const Widget & lhs, const Widget &rhs) {
            cout << "binary functor operator called " << m_x << " " << this << endl;
            return lhs.id < rhs.id;
        }
};

class unary_functor {
    public:
        unary_functor() {
            cout << "constructed unary functor " << this << endl;
        }
        bool operator() (const Widget &rhs) {
            cout << "unary functor operator called " << this << endl;
            return rhs.id > 5;
        }
};


void TestAlgorithmFunctors (vector<Widget> &v)
{
    v.reserve(0);
    for (int i = 0; i < 10; i++) {
        v.push_back(Widget(i));
    }

    srand(time(NULL));
    random_shuffle(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].id << " ";
    }
    cout << endl;

    // Erase all elements that are greater than 5
    sort(v.begin(), v.end(), binary_functor());
    v.erase(remove_if(v.begin(), v.end(), unary_functor()), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].id << " ";
    }
    cout << endl;
}

void TestSetFunctors (set<Widget, binary_functor> &s) {
    s.insert(Widget(0));
    s.insert(Widget(1));
    s.insert(Widget(0));

    for (set<Widget, binary_functor>::iterator itr = s.begin();
            itr != s.end(); itr++) {
        cout << "Set Widget " << (*itr).id << endl;
    }
    return;
}

void TestMapFunctors (map <Widget, int, binary_functor> &m) {
    m.insert(make_pair(Widget(0),0));
    m.insert(make_pair(Widget(1),10));
    m.insert(make_pair(Widget(2),20));

    for (map<Widget, int>::iterator itr = m.begin (); itr != m.end(); itr++) {
        cout << "Map Widget Key Widget( " << itr->first.id << ") Value " << itr->second << endl;
    }
}

int main () {
    vector<Widget> v;
    //set <Widget, binary_functor> s;
    binary_functor bf(3);
    map <Widget, int, binary_functor> m; // To pass a functor as an input

    //TestAlgorithmFunctors(v);
    //TestSetFunctors(s);
    TestMapFunctors(m);

    return 0;
}
