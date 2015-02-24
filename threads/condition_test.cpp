#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>

using namespace std;
typedef  vector<thread> vt;
mutex m;
condition_variable cv;
bool ready = false;

void workerRoutine(int id) {
    unique_lock<mutex> lock(m);
    cout << "Checking status .. " << id << endl;
    while(!ready) {
        cv.wait(lock);
    }
    cout << "I am ready .. " << id << endl;
    return;
}

void go() {
    unique_lock<mutex> lock(m);
    ready = true;
    cv.notify_all();
}

int main() {
    vt v;
    for (int i = 0; i < 10; i++) {
        v.push_back(thread(workerRoutine,i));
    }
    go();
    for (int i = 0; i < 10; i++) {
        v[i].join();
    }
}
