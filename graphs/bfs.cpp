#include <iostream>
#include <istream>
#include <fstream>
#include <queue>
#include "graph.h"
#include <algorithm>
#include <iterator>

enum color_t {WHITE,GREY,BLACK};

void bfs(Graph &g, int source, vector<int> &parents) {
    queue<int> Q;
    vector<color_t> visited(g.V,WHITE);
    int u,v;

    visited[source] = GREY;
    Q.push(source);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i].first;
            if (visited[v] == WHITE) {
                parents[v] = u;
                visited[v] = GREY;
                Q.push(v);
            }
        }
        visited[u] = BLACK;
    }
}

void printPath(vector<int> &parents, int v) {
    vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = parents[v];
    }
    //reverse(path.begin(),path.end());
    copy(path.rbegin(),path.rend(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main(int argc, char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    g.init_unweight(ifs);
    //g.print();
    vector<int> parents(g.V,-1);
    bfs(g,1,parents);
    for (int i = 1; i < parents.size(); i++) {
        printPath(parents,i);
    }
}
