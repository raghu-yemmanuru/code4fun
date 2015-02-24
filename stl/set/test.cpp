#include <iostream>
#include <set>
#include <string>

using namespace std;

class Widget {
    public:
        string name;
        Widget (string _name): name(_name) {}
        bool operator <(const Widget &rhs) const {
            return name < rhs.name;
        }
};

struct compare {
    bool operator()(const Widget &lhs, const Widget &rhs) {
        return lhs.name < rhs.name;
    }
};

class CompareKeys : public binary_function <Widget &, Widget &, bool> {
    public:
        bool operator()(const Widget &lhs, const Widget &rhs) {
            return lhs.name < rhs.name;
        }
};


//Any of these declarations will work
//typedef set<Widget, CompareKeys> WidgetSet;
typedef set<Widget, compare> WidgetSet;
//typedef set<Widget> WidgetSet;
//typedef set<Widget,less<Widget> > WidgetSet;

typedef WidgetSet::iterator WidgetSetItr;

int main () {
    WidgetSet myset;
    myset.insert(Widget("Raghu"));
    myset.insert(Widget("Harika"));
    myset.insert(Widget("Abhiram"));

    for (WidgetSetItr itr = myset.begin(); itr != myset.end();
            itr++) {
        cout << (*itr).name << endl;
    }

    return 0;
}
