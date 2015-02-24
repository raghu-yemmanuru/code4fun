#include <iostream>
#include <set>
#include <string>

using namespace std;

class Widget {
    public:
        string name;
        Widget (string _name): name(_name) {}
        bool operator <(Widget &rhs) {
            return name < rhs.name;
        }
};

int main () {
    Widget a("Abhiram");
    Widget b("Harika");
    cout << (b < a) << endl;
}
