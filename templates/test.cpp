#include <iostream>
using namespace std;

class C1 {
    private:
        int m_data;
    public:
        C1 (int data) : m_data(data) {}
        int getData() const {
            return m_data;
        }
};

class C2 {
    private:
        int m_data;
    public:
        C2 (int data) : m_data(data) {}
        int getData() const {
            return m_data;
        }
};

class C3 {
    private:
        int m_data;
    public:
        C3 (int data) : m_data(data) {}
        int getData() const {
            return m_data;
        }
};

class C4 {
    private:
        int m_data;
    public:
        typedef int INT;
        static int gc2;
        C4 (int data) : m_data(data) {}
        int getData() const {
            return m_data;
        }
};

int C4::gc2 = 3;

template<typename T>
void process(const T& c) {
    int data = c.getData();
    cout << " In general process " << data << endl;
}

template <>
void process <C4>(const C4& c) {
    C4::INT i = 5; //typename is mandatory to say its a type
    int data = c.getData();
    cout << " In specialized C4 process " << data << " " << c.gc2 << endl;
}


int main() {
    C1 c1(1);
    C2 c2(2);
    C3 c3(3);
    C4 c4(4);

    //General Process called
    process<C1>(c1);
    process<C2>(c2);
    process<C3>(c3);

    //Specialized template process called
    process<C4>(c4);
}
