#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int random_number() {
    return rand()%100;
}

int main () {
    stack<int> s1,s2;
    int count = 0;

    srand(time(NULL));
    cin >> count;
    while (count--) {
        int val = random_number();
        cout << val << " ";
        s1.push(val);
    }
    cout << endl;

    while(!s1.empty()) {
        int val = s1.top();
        s1.pop();
        while (!s2.empty() && val > s2.top()) {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(val);
    }

    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}


