#include <iostream>
using namespace std;

class BaseWidget {
    public:
        BaseWidget() {
            cout << "Base Widget construction " << this << endl;
        }
        void mf1() {
            cout << "void BaseWidget::mf1()" << endl;
        }
        int mf1(int) {
            cout << "int BaseWidget::mf1(int)" << endl;
            return 0;
        }
        ~BaseWidget() {
            cout << "Base Widget destroy " << this << endl;
        }
};

class DerivedWidget: public BaseWidget {
    public:
        using BaseWidget::mf1;
        DerivedWidget(): BaseWidget() {
            cout << "Derived Widget construction " << this << endl;
        }
        int mf1() {
            cout << "int DerivedWidget::mf1()" << endl;
        }
        ~DerivedWidget() {
            cout << "DerivedWidget destruction " << this << endl;
        }
};

int main() {
    BaseWidget *bw = new BaseWidget();
    DerivedWidget *dw = new DerivedWidget();

    bw->mf1();
    bw->mf1(0);

    dw->mf1();
    dw->mf1(0); //Will not work as name is hidden unless we use using

    delete bw;
    delete dw;
    return 0;
}
