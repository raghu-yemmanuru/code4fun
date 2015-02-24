#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

typedef vector<int> vi;
enum color_t {WHITE=0,GREY,BLACK};
class Graph {
public:
    vector<int> *adj;
    int V;
    Graph(int _v):V(_v){
        adj = new vector<int>[V];
    }
    ~Graph() {
        delete[] adj;
    }
};

void bfs(Graph &g, vi &parents, int src)  {
    vector<color_t> visited(g.V,WHITE);
    parents[src] = 0;
    visited[src] = GREY;

    queue<int> Q;
    Q.push(src);
    int u,v;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < g.adj[u].size(); i++) {
            v = g.adj[u][i];
            if (visited[v] == WHITE) {
                parents[v] = u;
                visited[v] = GREY;
                Q.push(v);
            }
        }
        visited[u] = BLACK;
    }
}
    
int main() {
    Graph g(7);
    g.adj[0].push_back(1);
    g.adj[0].push_back(3);
    g.adj[1].push_back(2);
    g.adj[2].push_back(4);
    g.adj[3].push_back(5);
    g.adj[3].push_back(2);
    g.adj[4].push_back(6);
    g.adj[5].push_back(6);
    vector<int> parents(g.V,-1);
    bfs(g,parents,0);

    copy(parents.begin(),parents.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
