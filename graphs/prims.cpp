#include <iostream>
#include "graph.h"
#include <vector>
#include <fstream>
#include <limits>
#include <iterator>
#include <set>

using namespace std;
typedef set<pair<double,int> > Set;


void prims(Graph &g, vector<int> &parents) {
    double inf = numeric_limits<double>::infinity();
    vector<double> keys(g.V,inf);
    Set s;

    keys[1] = 0;
    s.insert(make_pair(0,1));
    for (int i = 2; i < g.V; i++) {
        s.insert(make_pair(inf,i));
    }

    Set::iterator itr;
    int u,v;
    double w;
    while (!s.empty()) {
        itr = s.begin();
        u = itr->second;
        s.erase(itr);
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i].first;
            w = (double) g.adj[u][i].second;
            itr = s.find(make_pair(keys[v],v));
            if (itr != s.end() && keys[v] > w) {
                s.erase(itr);
                keys[v] = w;
                parents[v] = u;
                s.insert(make_pair(keys[v],v));
            }
        }
    }
}

void printTreeWeight(Graph &g, vector<int> &parents) {
    int u,v;
    int weight = 0;
    for (int u = 1; u < parents.size(); u++) {
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i].first;
            if (parents[v] == u) {
                weight += g.adj[u][i].second;
            }
        }
    }
    cout << weight << endl;
}
                
        

int main(int argc, char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    
    g.init_undirect(ifs);
    vector<int> parents(g.V,-1);
    //g.print();
    prims(g,parents);
    for (int i = 0; i < parents.size(); i++) {
        cout << i << "   ";
    }
    cout << endl;
    copy(parents.begin(),parents.end(),ostream_iterator<int>(cout,"   "));
    cout << endl;
    printTreeWeight(g,parents);
    //g.print();
}
