#include <iostream>
#include <typeinfo>

using namespace std;

class BaseWidget {
    public:
        string getName() {
            return "BaseWidget";
        }
        virtual ~BaseWidget() {}
};

class DerivedWidget : public BaseWidget {
    public:
        string getName() {
            return "DerivedWidget";
        }
};

int main() {
    BaseWidget bw;
    DerivedWidget dw,dw1;
    BaseWidget *pbw;
    DerivedWidget *pdw;

    pbw = &bw;
    cout << typeid(*pbw).name() << endl;

    // If virtual function is not present in base class,
    // typeid will be compile time generated
    pbw = &dw;
    cout << typeid(*pbw).name() << endl;

    pbw = &dw;
    pdw = &dw1;
    if (typeid(*pbw) == typeid(*pdw)) { // If * is  missing it wont pass as pointer types are compile time known
        cout << "both pointers point to same type" << endl;
    }

    return 0;
}
