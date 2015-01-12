#include <iostream>
#include "graph.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;
enum color_t {White,Grey,Black};
struct node {
    int start;
    int end;
    int parent;
};

int visited_time = 0;

void dfsUtil (Graph &g, int u, vector<node> &nodes, vector<color_t> &visited) {
    nodes[u].start = ++visited_time;
    visited[u] = Grey;

    for (int i = 0; i < g.adj[u].size(); i++) {
        int v = g.adj[u][i].first;
        if (visited[v] == Grey) {
            cout << "Cycle Detected " << endl;
            exit(1);
        }

        if (visited[v] == White) {
            nodes[v].parent = u;
            dfsUtil(g,v,nodes,visited);
        }
    }

    visited[u] = Black;
    nodes[u].end = ++visited_time;
}
        
void dfs(Graph &g, vector<node> &nodes) {
    vector<color_t> visited(g.V, White);
    for (int i = 1; i < g.V; i++) {
        if (visited[i] == White) {
            dfsUtil(g,i,nodes,visited);
        }
    }
}

int main(int argc, char **argv) {
    ifstream ifs(argv[1]);
    Graph g;
    g.init(ifs);

    node dummy = {0,0,-1};
    vector<node> nodes(g.V,dummy);

    dfs(g,nodes);
    vector<pair<int,int> > v;
    for (int i = 1; i < nodes.size();i++) {
        v.push_back(make_pair(nodes[i].end,i));
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << " ";
    }
    cout << endl;
}
