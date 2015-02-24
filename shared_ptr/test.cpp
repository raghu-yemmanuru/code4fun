#include <boost/shared_ptr.hpp>
#include <iostream>
#include <vector>

using namespace boost;
using namespace std;

class Widget {
    private:
        int data;
    public:
        Widget (int _data): data(_data) {
            cout << "Constructed " << this << endl;
        }
        int getData () const {
            return data;
        }
        ~Widget() {
            cout << "Destroyed " << this << endl;
        }
};
typedef shared_ptr<Widget> WidgetPtr;
typedef shared_ptr<int> intPtr;

class Leaker {
    private:
        vector<WidgetPtr> vw;
    public:
        Leaker() {
            for (int i = 0; i < 10; i++) {
                vw.push_back(WidgetPtr(new Widget(i)));
            }
        }
        ~Leaker() {}
};


bool isOdd (const WidgetPtr & w) {
    return (w->getData() % 2);
}

int main() {
    /*vector<WidgetPtr> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(WidgetPtr(new Widget(i)));
    }

    vec.erase(remove_if(vec.begin(), vec.end(), isOdd), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        cout << "Elements present " << vec[i]->getData() << endl;
    }*/
    Leaker *lp = new Leaker();
    //delete lp; ==> This will leak the vector with shared pointers as well
    return 0;
}
