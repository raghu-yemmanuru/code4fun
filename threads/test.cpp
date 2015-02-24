#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

void* print_message(void* ptr) {
    string *s = (string *) ptr;
    cout << "Hello" << *s << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }
}

int main() {
    vector<pthread_t> v;
    for (int i = 0; i < 5; i++) {
        pthread_t t;
        v.push_back(t);
    }

    for (int i = 0; i < 5; i++) {
        string input = "hello";
        pthread_create(&v[i],NULL,print_message,&input);
        pthread_join(v[i],NULL);
    }
}
