#include <thread>
#include <iostream>
#include <vector>

//using namespace std;
//typedef vector<thread> vt;

void print_id(int id) {
    std::cout << "Running new thread with id " << id << std::endl;
}

int main() {
    //vt v(5);
    int id = 0;
    std::thread t(print_id,id);
    t.join();
}
