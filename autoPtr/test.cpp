#include <iostream>
using namespace std;
//using namespace::std::tr1;

class Widget {
    private:
        int m_data;
    public:
    explicit Widget():m_data(0) {
        cout << "Inside widget constructor " << this << endl;
    }
    void setData(int val) {
        m_data = val;
        return;
    }

    int getData() const {
        return m_data;
    }

    ~Widget() {
        cout << "Inside widget destructor " << this << endl;
    }
};

int main() {
    auto_ptr<Widget> wptr (new Widget());
    auto_ptr<Widget> wptr1;
    shared_ptr<Widget> swptr;
    wptr1 = wptr;
    if (!wptr.get()) {
        cout << "wptr is NULL" << endl;
        return -1;
    }
    wptr->setData(3);
    cout << "data " << wptr->getData() << endl;
    //tr1::shared_ptr<Widget> swptr (new Widget());
}
