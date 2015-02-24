#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

int main() {
    srand(time(NULL));
    queue<int> q;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 1000;
        cout << "pushing " << val << endl;
        q.push(val);
    }

    cout << "Queue size " << q.size() << endl;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
