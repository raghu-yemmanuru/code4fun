#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
enum color_t {white,grey,black};

class Graph {
private:
    int V;
    vector<int> *adj;
public:
    Graph (int _V): V(_V){
        adj = new vector<int>[V];
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
    }
    void bfs(int s,vector<int> &parents) {
        vector<color_t> colors (V,white);
        queue<int> q;

        if (s >= V) {
            cout << "Invalid vertex " << endl;
            return;
        }
        colors[s] = grey;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (colors[v] == white) {
                    parents[v] = u;
                    colors[v] = grey;
                    q.push(v);
                }
            }
            colors[u] = black;
        }
        return;
    }
    void printPath(int s, int t) {
        vector<int> parents(V,-1);
        vector<int> path;
        bfs(s,parents);
        int i = 0;
        for (i = t; i != -1; i = parents[i]) {
            path.push_back(i);
            if (i == s) {
                break;
            }
        }
        if (i != s) {
            cout << "No path" << endl;
        } else {
            reverse(path.begin(), path.end());
            for (int j = 0; j < path.size(); j++)
                cout << path[j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,4);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(1,4);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printPath(1,3);
}
