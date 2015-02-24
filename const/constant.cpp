#include <iostream>
using namespace std;

class ConstTester {
    private:
        int m_key;
    public:
        ConstTester(): m_key(0) {
        };
        int getData() const;
        void setData (const int);
};

int ConstTester::getData() const {
    return m_key;
}

void ConstTester::setData(const int newKey) {
    m_key = newKey;
    return;
}

void testConstantTester () {
    ConstTester ct;
    const ConstTester cct;
    cout << ct.getData() << endl;
    ct.setData(2);
    cout << ct.getData() << endl;

    cout << cct.getData() << endl;
    cct.setData(3); // NOT OK
    cout << cct.getData() << endl;
}

int main() {
    char str[] = "abcdefgh";

    char *ptr = &str[2];
    // can change ptr data
    *ptr = 'z';
    cout << *ptr << endl;

    // Pointed data is const. pointer can point else where
    const char *PtrToConstData = &str[3];
    cout << *PtrToConstData << endl;
    // *PtrToConstData = 'x'; // NOT OK
    PtrToConstData = NULL; // OK

    char* const constPtr = &str[4];
    cout << *constPtr << endl;
    *constPtr = 'x'; // OK
    //consPtr = NULL; // Not OK
    
    const char* const constPtrToConstData = &str[4];
    cout << *constPtrToConstData << endl;
    //*constPtrToConstData = 'y'; // NOT OK
    //constPtrToConstData = NULL; // NOT OK

    testConstantTester();

    return 0;
}
