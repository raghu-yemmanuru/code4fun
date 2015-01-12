#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <set>
#include <limits>
#include "graph.h"

using namespace std;
typedef pair<double,int> Pair;
typedef set<Pair> Set;

void dijkstra(Graph &g, int source, vector<int> &parents) {
    double inf = numeric_limits<double>::infinity();
    vector<double> dist(g.V,inf);
    Set s;

    dist[source] = 0;
    for (int i = 1; i < dist.size(); i++) {
        s.insert(make_pair(dist[i],i));
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
            w = g.adj[u][i].second;
            itr = s.find(make_pair(dist[v],v));
            if (itr != s.end() && dist[v] > dist[u] + w) {
                s.erase(itr);
                dist[v] = dist[u] + w;
                parents[v] = u;
                s.insert(make_pair(dist[v],v));
            }
        }
    }
}

void printPath(int v, vector<int> &parents) {
    vector<int> path;
    while (v != -1) {
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
    dijkstra(g,1,parents);

    for (int i = 1; i < g.V; i++) {
        printPath(i,parents);
    }
}
