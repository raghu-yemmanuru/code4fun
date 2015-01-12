#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iterator>
#include "graph.h"

using namespace std;
double inf = numeric_limits<double>::infinity();

void bellman_ford(Graph &g, int s, vector<int> &parents, vector<double> &dist) {
    int v,w;
    dist[s] = 0;
    for (int i = 1; i < g.V-1; i++) {
        //For all verticies
        for (int u = 1; u < g.V; u++) {
            for (int i = 0; i < g.adj[u].size(); i++) {
                v = g.adj[u][i].first;
                w = g.adj[u][i].second;
                //Relax each edge
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parents[v] = u;
                }
            }
        }
    }
}

void printPath(vector<int> &parents, int v) {
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
    vector<double> dist(g.V,inf);
    int source = 1;

    bellman_ford(g,source,parents,dist);
    for (int i = 1; i < g.V; i++) {
        printPath(parents,i);
    }
}
