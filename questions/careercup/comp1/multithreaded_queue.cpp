#include <iostream>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

template<class T>
class DQueue {
private:
    queue<T> Q;
    int capacity;
    mutex m;
    condition_variable m_waitQ;

public:
    DQueue(int _c):capacity(_c){}
    void push(T &val) {
        unique_lock<mutex> lock(m);
        while (Q.size() == capacity) {
            m_waitQ.wait(lock);
        }
        Q.push(val);
        m_waitQ.notify_one();
        return;
    }

    T pop() {
        unique_lock<mutex> lock(m);
        while(Q.size() == 0) {
            m_waitQ.wait(lock);
        }
        T val = Q.front();
        Q.pop();
        m_waitQ.notify_one();
        return val;
    }

    bool try_pop(T &val) {
        unique_lock<mutex> lock(m);
        if (Q.size() == 0) {
            return false;
        }
        val = Q.front();
        Q.pop();
        m_waitQ.notify_one();
        return true;
    }
};

void produce(DQueue<int> *p_dq) {
    int v;
    while(true) {
        v = rand();
        cout << "Trying to Push " << v << endl;
        p_dq->push(v);
        cout << "Pushed " << v << endl;
        sleep(5);
        //this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void consume(DQueue<int> *p_dq) {
    int r;
    while(true) {
        cout << "Trying to consume " << endl;
        r = p_dq->pop();
        cout << "Consumed " << r << endl;
        sleep(1);
        //this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() {
    srand(time(NULL));
    DQueue<int> dq(10);
    thread producer(produce,&dq);
    thread consumer(consume,&dq);

    producer.join();
    consumer.join();
} 
