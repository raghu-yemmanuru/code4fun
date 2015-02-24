#include <iostream>
#include <set>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;
struct node {
    int data;
    int row;
    int col;
    node(int _d, int _r, int _c):data(_d),row(_r),col(_c){}
};

struct nodeCompare {
    bool operator()(const node &lhs, const node &rhs) {
        return lhs.data < rhs.data;
    }
};

typedef vector<int> vi;
typedef vector<vi > vvi;
typedef set<node,nodeCompare> Setn;

void findMinWindow(const vvi &Grid) {
    Setn s;
    for (int i = 0; i < Grid.size(); i++) {
        s.insert(node(Grid[i][0],i,0));
    }
    Setn::iterator itr1,itr2;
    vi window;
    int minWindow = numeric_limits<int>::max();
    while(s.size() == Grid.size()) {
        itr1 = s.begin();
        itr2 = s.end();
        --itr2;
        if (itr2->data - itr1->data < minWindow) {
            window.clear();
            for (Setn::iterator itr = s.begin(); itr != s.end(); itr++) {
                window.push_back(itr->data);
            }
            minWindow = itr2->data - itr1->data;
        }
        int r = itr1->row;
        int c = itr1->col;
        s.erase(itr1);
        if (c < Grid[r].size()-1) {
            s.insert(node(Grid[r][c+1],r,c+1));
        }
    }
    copy(window.begin(),window.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    return;
}

int main() {
    int r,c;
    cin >> r >> c;
    vvi G(r,vi(c,0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> G[i][j];
        }
    }
    findMinWindow(G);
}
