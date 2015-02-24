#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int w;
    int num;
    cin >> w;
    deque<int> Q;
    vector<int> v;
    int i = 0;
    for (i = 0; i < w; i++) {
        cin >> num;
        v.push_back(num);
        while(!Q.empty() && v[Q.back()] < num) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout << "Max : " << v[Q.front()] << endl;

    i--;
    while(cin >> num) {
        v.push_back(num);
        i++;
        while (!Q.empty() && v[Q.back()] < num) {
            Q.pop_back();
        }
        while (!Q.empty() && Q.front() <= i-w) {
            Q.pop_front();
        }
        Q.push_back(i);
        cout << "Max : " << v[Q.front()] << endl;
    }
}
