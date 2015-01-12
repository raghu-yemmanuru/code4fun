#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <iterator>
#include "graph.h"

double inf = numeric_limits<double>::infinity();

void toplogical_short(Graph &g,int s,vector<int> &parents) {
    int v,w;
    vector<double> dist(g.V,inf);
    dist[s] = 0.0;
    for (int u = 1; u < g.V; u++) {
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i].first;
            w = g.adj[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parents[v] = u;
            }
        }
    }
    copy(dist.begin()+1,dist.end(),ostream_iterator<double>(cout, " "));
    cout << endl;
}

void printPaths(Graph &g, int v, vector<int> &parents) {
    vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = parents[v];
    }
    copy(path.rbegin(),path.rend(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main(int argc, char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    g.init(ifs);

    vector<int> parents(g.V,-1);
    toplogical_short(g,2,parents);

    for (int i = 1; i < g.V; i++) {
        printPaths(g,i,parents);
    }
}
