#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template <class T, class Container=deque<T> >
class MyStack {
typedef T value_type;
typedef Container container_type;
private:
    container_type m_cont;
public:
    void push(const T &);
    void pop();
    T top();
    bool empty();
};

template <class T, class Container>
bool MyStack<T,Container>::empty() {
    return m_cont.empty();
}

template <class T, class Container>
void MyStack<T,Container>::push(const T& item) {
    m_cont.push_back(item);
}

template <class T, class Container>
T MyStack<T,Container>::top() {
    return m_cont.back();
}

template <class T, class Container>
void MyStack<T,Container>::pop() {
    m_cont.pop_back();
    return;
}    

int main() {
    MyStack<string> ms;
    ms.push("hello");
    ms.push("hi");
    ms.push("whats up");
    
    while (!ms.empty()) {
        cout << ms.top() << endl;
        ms.pop();
    }
}
