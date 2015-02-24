#include <iostream>
#include <vector>
using namespace std;

class Widget {
    public:
        Widget() {
            cout << "Widget constructed " << this << endl;
        }
        Widget (const Widget &) {
            cout << "Widget copy constructed " << this << endl;
        }
        ~Widget () {
            cout << "Widget destroyed " << this << endl;
        }
};

int main() {
    vector<int> v;
    vector<Widget> vw;
    vw.reserve(3);
    for (int i = 0; i < 3; i++) {
        Widget w;
        vw.push_back(w);
    }

    cout << "All elements are pushed to vector " << endl;
    return 0;
}
