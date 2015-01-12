#include <iostream>
#include <vector>
#include "disjoint.h"
#include "graph.h"
#include <iterator>
#include <map>

using namespace std;

typedef pair<int,int> IntPair;
typedef vector<IntPair> PairVector;

void kruskal(Graph &g, PairVector &pv) {
    multimap<int,pair<int,int> > weightMap;
    DisjointSets ds(g.V);

    for (int u = 1; u < g.V; u++) {
        ds.makeset(u);
        for (int i = 0; i < g.adj[u].size(); i++) {
            int v = g.adj[u][i].first;
            int weight = g.adj[u][i].second;
            weightMap.insert(make_pair(weight,make_pair(u,v)));
        }
    }


    int weight = 0;
    multimap<int,pair<int,int> >::iterator itr;
    for (itr = weightMap.begin(); itr != weightMap.end() && pv.size() < g.V-1; itr++) {
        int u = itr->second.first;
        int v = itr->second.second;
        if (ds.find(u) != ds.find(v)) {
            weight += itr->first;
            pv.push_back(make_pair(u,v));
            ds.unite(u,v);
        }
    }
    cout << "Weight of spanning Tree " << weight << endl;
}

int main(int argc, char **argv) {
    Graph g;

    ifstream ifs(argv[1]);
    g.init_undirect(ifs);
    g.print();

    PairVector pv;
    kruskal(g,pv);
    for (int i = 0; i < pv.size(); i++) {
        cout << "{" << pv[i].first << "," << pv[i].second << "}, ";
    }
    cout << endl;
}

