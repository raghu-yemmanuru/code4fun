#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <limits>
#include <queue>
#include <fstream>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

struct node {
    int r,c;
    int data;
    node(int _data,int _r, int _c):data(_data),r(_r),c(_c){}
};

struct nodeCompare {
    bool operator()(node &lhs, node &rhs) {
        return lhs.data > rhs.data;
    }
};

typedef priority_queue<node,vector<node>,nodeCompare> pqn;


int kthSmallest(vvi &G, int k) {
    pqn pq;
    for (int i = 0; i < G.size(); i++) {
        pq.push(node(G[0][i],0,i));
    }
    int count = 0;
    node tmp(-1,-1,-1);
    while(!pq.empty() && count < k) {
        tmp = pq.top();
        pq.pop();
        if (tmp.r < G.size()-1) {
            pq.push(node(G[tmp.r+1][tmp.c],tmp.r+1,tmp.c));
        }
        count++;
    }
    if (pq.empty()) {
        return -1;
    }
    tmp = pq.top();
    return tmp.data;
}

int main(int argc, char **argv) {
    int num;
    ifstream ifs(argv[1]);
    ifs >> num;
    vvi G(num,vi(num,0));
    for (int i = 0; i < num;i++) {
        for (int j = 0; j < num; j++) {
            ifs >> G[i][j];
        }
    }
    int k;
    ifs >> k;

    cout << "Value is " << kthSmallest(G,k) << endl;
            
    return 0;
}
