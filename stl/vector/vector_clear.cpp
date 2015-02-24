#include <iostream>
#include <vector>

using namespace std;

class Widget {
public:
    Widget() {
        cout << "Constructed " << this << endl;
    }
    ~Widget() {
        cout << "Destructed " << this << endl;
    }
};

int main() {
    vector<Widget*> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(new Widget());
    }

    //v.clear();
    vector<Widget*>::iterator itr;
    for (itr = v.begin(); itr != v.end();) {
        delete *itr;
        itr = v.erase(itr);
    }
    cout << v.size() << endl;
}
