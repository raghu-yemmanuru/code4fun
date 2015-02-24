#include <set>
#include <iostream>
#include <cstdlib>

using namespace std;

struct val {
    int num;
    int id;
    val(int _num,int _id): num(_num),id(_id) {}
};

struct compare {
    bool operator()(const struct val &lhs, const struct val &rhs) {
        return lhs.num < rhs.num;
    }
};

void printSet(multiset<val,compare> &s) {
    for (set<val,compare>::iterator itr = s.begin(); itr != s.end(); itr++) {
        //cout << "(" << itr->num << " " << itr->id <<")";
        cout << itr->num << " ";
    }
        cout << endl;
}

int main() {
    multiset<val,compare> s;
    srand(time(NULL));
    multiset<val,compare>::iterator itr;
    for (int i = 0;i < 20; i++) {
        int num = rand()%10;
        s.insert(val(num,i));
        if (s.size() == 1) {
           itr = s.begin();
        } else if (s.size() % 2 == 1 && num < itr->num) {
            itr--;
        } else if (s.size() %2 == 0 && num >= itr->num) {
            itr++;
        }
        cout << "Median is ";
        if (s.size()%2 == 1) {
            cout << itr->num << endl;    
        } else {
            multiset<val,compare>::iterator prev;
            prev = --itr;
            itr++;
            cout << ((prev->num) + (itr->num)) / 2.0 << endl;
        }
        printSet(s);
    }
}
