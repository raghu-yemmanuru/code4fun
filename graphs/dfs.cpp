#include <iostream>
#include <vector>
#include "graph.h"
#include <map>

struct node {
    int start;
    int end;
    int parent;
};
enum color_t {White,Grey,Black};
int visited_time = 0;
typedef vector<Pair> PairVector;
typedef map<string,PairVector> EdgeMap;

EdgeMap edgeMap;

void processEdge(Pair edge, vector<node> &nodes, vector<color_t> &visited) {
    int u = edge.first;
    int v = edge.second;

    if (visited[v] == White) {
        edgeMap["tree"].push_back(edge);
    } else if (visited[v] == Grey) {
        edgeMap["back"].push_back(edge);
    } else { // black
        if (nodes[v].start < nodes[u].start) {
            edgeMap["cross"].push_back(edge);
        } else {
            edgeMap["forward"].push_back(edge);
        }
    }
} 

void dfsUtil(Graph &g, int u, vector<node> &nodes, vector<color_t> &visited) {
    visited[u] = Grey;
    nodes[u].start = ++visited_time;

    for (int i = 0; i < g.adj[u].size(); i++) {
        int v = g.adj[u][i].first;
        if (visited[v] == White) {
            nodes[v].parent = u;
            processEdge(make_pair(u,v),nodes,visited);
            dfsUtil(g,v,nodes,visited);
        } else {
            processEdge(make_pair(u,v),nodes,visited);
        }
    }

    visited[u] = Black;
    nodes[u].end = ++visited_time;
}

void dfs(Graph &g,vector<node> &nodes) {
    vector<color_t> visited(g.V,White);
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == White) {
            dfsUtil(g,i,nodes,visited);
        }
    }
}

void printTimes(vector<node> &nodes) {
    for (int i = 1; i < nodes.size(); i++) {
        cout << i << " " << nodes[i].start << " " << nodes[i].end << endl;
    }
}

void classifyEdges(Graph &g, vector<node> &nodes) {
    cout << "Tree Edges " << endl;
    PairVector pv;
    pv = edgeMap["tree"];
    for (int i = 0; i < pv.size(); i++) {
       cout << "(" << pv[i].first << " " << pv[i].second << ") ";
    }
    cout << endl;

    cout << "Back Edges " << endl;
    pv = edgeMap["back"];
    for (int i = 0; i < pv.size(); i++) {
       cout << "(" << pv[i].first << " " << pv[i].second << ") ";
    }
    cout << endl;

    cout << "Forward Edges " << endl;
    pv = edgeMap["forward"];
    for (int i = 0; i < pv.size(); i++) {
       cout << "(" << pv[i].first << " " << pv[i].second << ") ";
    }
    cout << endl;

    cout << "Cross Edges " << endl;
    pv = edgeMap["cross"];
    for (int i = 0; i < pv.size(); i++) {
       cout << "(" << pv[i].first << " " << pv[i].second << ") ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    g.init(ifs);
    g.print();
    node dummy = {0,0,-1};

    vector<node> nodes(g.V,dummy);
    dfs(g,nodes);

    printTimes(nodes);
    edgeMap.insert(make_pair("tree", PairVector()));
    edgeMap.insert(make_pair("back", PairVector()));
    edgeMap.insert(make_pair("cross", PairVector()));
    edgeMap.insert(make_pair("forward", PairVector()));
    classifyEdges(g,nodes);
}
