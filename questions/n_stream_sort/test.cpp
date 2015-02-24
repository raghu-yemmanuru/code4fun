#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


int main() {
    int val = -1;
    fstream ifs0;
    ifs0.open("1.dat",fstream::in);

    fstream ifs1;
    ifs1.open("2.dat",fstream::in);

    fstream ifs2;
    ifs2.open("3.dat",fstream::in);

    vector<fstream *> streams;

    streams.push_back(&ifs0);
    streams.push_back(&ifs1);
    streams.push_back(&ifs2);

    vector<pair<int,int> > min_heap;
    make_heap(min_heap.begin(), min_heap.end(), greater<pair<int,int> >());

    for (int i = 0; i < streams.size(); i++) {
        if (*(streams[i]) >> val) {
            min_heap.push_back(make_pair(val,i));
            push_heap(min_heap.begin(), min_heap.end(), greater<pair<int,int> >());
        }
    }

    while (!min_heap.empty()) {
        pair<int,int> p = min_heap.front();
        cout << p.first << endl;
        pop_heap(min_heap.begin(), min_heap.end(), greater<pair<int,int> >());
        min_heap.pop_back();


        int sid = p.second;
        if (*(streams[sid]) >> val) {
            min_heap.push_back(make_pair(val, sid));
            push_heap(min_heap.begin(), min_heap.end(), greater<pair<int,int> >());
        }
    }

    for (int i = 0; i < streams.size(); i++) {
        streams[i]->close();
    }
}
