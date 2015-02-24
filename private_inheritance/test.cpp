#include <iostream>
using namespace std;

class BaseWidget {
    protected:
        void basef2() {
            cout << "void BaseWidget::basef2() " << endl;
        }
    public:
        BaseWidget() {
            cout << "BaseWidget construction " << this << endl;
        }
        void basef1() {
            cout << "void BaseWidget::basef1() " << endl;
        }
};

class DerivedWidget: private BaseWidget {
    public:
        DerivedWidget(): BaseWidget() {
            cout << "DerivedWidget construction " << this << endl;
        }
        void derivef1() {
            BaseWidget::basef1(); // These will work even in private inheritance
            BaseWidget::basef2(); // These will work even in private inheritance
            cout << "void DerivedWidget::derivef1() " << endl;
        }
};

int main() {
    BaseWidget bw;
    // bw.basef2(); ==> Wil fail as basef2() is protected

    DerivedWidget dw;
    dw.derivef1();
    //dw.basef1(); //==> Will fail as inheritence is private
    //dw.basef2(); // ==> will fail as inheritence is private
    return 0;
};

