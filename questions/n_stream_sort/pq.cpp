#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;


int main() {
    int val = -1;
    ifstream ifs0;
    ifs0.open("1.dat");

    ifstream ifs1;
    ifs1.open("2.dat");

    ifstream ifs2;
    ifs2.open("3.dat");

    vector<ifstream *> streams;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > min_heap;

    streams.push_back(&ifs0);
    streams.push_back(&ifs1);
    streams.push_back(&ifs2);

    for (int i = 0; i < streams.size(); i++) {
        if (*(streams[i]) >> val) {
            min_heap.push(make_pair(val,i));
        }
    }

    while (!min_heap.empty()) {
        pair<int,int> p = min_heap.top();
        cout << p.first << endl;
        min_heap.pop();

        int sid = p.second;
        if (*(streams[sid]) >> val) {
            min_heap.push(make_pair(val, sid));
        }
    }

    for (int i = 0; i < streams.size(); i++) {
        streams[i]->close();
    }
}
