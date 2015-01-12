#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <limits>
#include "graph.h"

using namespace std;
typedef vector<double> vd;
typedef vector<vd > vvd;

void floyd_warshall(Graph &g, vvd &vd) {
    int v,w;
    for (int u = 1; u < g.V; u++) {
        vd[u][u] = 0;
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i].first;
            w = g.adj[u][i].second;
            vd[u][v] = w;
        }
    }

    for (int k = 1; k < g.V; k++) {
        for (int i = 1; i < g.V; i++) {
            for (int j = 1; j < g.V; j++) {
                if (vd[i][j] > vd[i][k] + vd[k][j]) {
                    vd[i][j] = vd[i][k] + vd[k][j];
                }
            }
        }
    }
}

int main(int argc,char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    g.init(ifs);
    g.print();

    vvd v;
    double inf = numeric_limits<double>::infinity();
    v.assign(g.V,vector<double>(g.V,inf));
    floyd_warshall(g,v);

    for (int i = 1; i < v.size(); i++) {
        for (int j = 1; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
