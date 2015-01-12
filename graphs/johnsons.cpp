#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <limits>
#include "graph.h"

void bellman_fords(Graph &g, int source, vector<double> &dist, vector<int> &parents) {
    int v;
    double w;
    dist[source] = 0;
    cout << "source is " << source << endl;
    cout << dist[source] << endl;
    for (int l = 1; l < g.V-1; l++) {
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
    }
}

int main(int argc, char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    g.init(ifs);
    g.print();

    double inf = numeric_limits<double>::infinity();
    vector<double> h(g.V,inf);

    Graph g1(g);
    g1.V = g1.V+1;
    g1.adj.push_back(vector<pair<int,double> >());

    int new_v = g1.V-1;
    for (int i = 1; i < g.V; i++) {
        g1.adj[new_v].push_back(make_pair(i,0));
    }
    g1.print(true);

    vector<double> dist(g1.V,inf);
    vector<int> parents(g1.V,-1);
    bellman_fords(g1,new_v,dist,parents);

    for (int i = 1; i < g1.V; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    for (int u = 1; u < g1.V; u++) {
        for (int i = 0; i < g1.adj[u].size(); i++) {
            int v = g1.adj[u][i].first;
            int w = g1.adj[u][i].second;
            g1.adj[u][i].second += dist[u] - dist[v];
        }
    }
    g1.print(true);
        
        
}
