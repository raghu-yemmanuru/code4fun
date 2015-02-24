#include <iostream>
using namespace std;

class BaseWidget {
    public:
        BaseWidget() {
        }
        virtual void mf1();
        virtual void mf2() = 0;
};

void BaseWidget::mf1(void) {
    cout << "void BaseWidget::mf1(void) " << endl;
}

void BaseWidget::mf2(void) {
    cout << "void BaseWidget::mf2(void) " << endl;
}

class DerivedWidget: public BaseWidget {
    private:
        int m_data;
    public:
        DerivedWidget(int data):
            BaseWidget(),
            m_data(data) {
        }
        void mf2() {
            BaseWidget::mf2();
            cout << "void DerivedWidget::mf2(void)" << endl;
        }
};

int main() {
    //BaseWidget bw; // should fail compilation
    BaseWidget *bdw = new DerivedWidget(3);
    bdw->mf1();
    bdw->mf2(); //Polymorphism ensures Derived one is called
    return 0;
}

