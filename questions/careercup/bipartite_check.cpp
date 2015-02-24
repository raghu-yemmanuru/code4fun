#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
enum color_t {WHITE=0,BLACK};
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef map<int,color_t> Map;

struct Graph {
    int V;
    vvi adj;
    Graph (int _v):V(_v) {
        adj.assign(V,vi());
    }
    bool addEdge(int u,int v) {
        if (u >= 0 && u < V) {
            adj[u].push_back(v);
            return true;
        }
        cout << "Error " << endl;
        return false;
    }
};

color_t compliment(color_t c) {
    if (c == WHITE) {
        return BLACK;
    } else {
        return WHITE;
    }
}

bool bipartite(Graph &g) {
    Map m;
    int source = 0;
    queue<int> q;
    q.push(source);
    m[source] = WHITE;

    int u,v;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i];
            if (m.find(v) != m.end()) {
                if (m[v] == m[u]) {
                    return false;
                }
            } else {
                m[v] = compliment(m[u]);
                q.push(v);
            }
        }
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    Graph g(num);
    int u,v;
    while(cin >> u >> v) {
        g.adj[u].push_back(v);
    }
    if (bipartite(g)) {
        cout << "Graph is bipartite " << endl;
    } else {
        cout << "Graph is not bipartite " << endl;
    }
}
