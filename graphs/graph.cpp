#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <istream>

using namespace std;

class Graph {

typedef pair<int,double> Pair;
typedef vector<Pair> List;

public:
    int V;
    vector<List> adj;
    void init(istream &);
    void init_unweight(istream &);
    void init_undirect(istream &);
    void print(bool);
};

void Graph::init(istream &is) {
    int u,v;
    double weight;
    is >> V;
    V++;
    adj.assign(V,List());// = new List[V];
    while(is >> u >> v >> weight) {
        adj[u].push_back(make_pair(v,weight));
    }
}

void Graph::init_unweight(istream &is) {
    int u,v;
    double weight;
    is >> V;
    V++;
    //adj = new List[V];
    adj.assign(V,List());// = new List[V];
    while(is >> u >> v) {
        adj[u].push_back(make_pair(v,1));
        adj[v].push_back(make_pair(u,1));
    }
}

void Graph::init_undirect(istream &is) {
    int u,v;
    double weight;
    is >> V;
    V++;
   //adj = new List[V];
    adj.assign(V,List());// = new List[V];
    while(is >> u >> v >> weight) {
        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }
}

void Graph::print(bool weights = false) {
    for (int i = 1; i < V; i++) {
        cout << "[ " << i << " ] ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "=> ( " << adj[i][j].first;
            if (weights) {
                cout << "," << adj[i][j].second;
            }
            cout << " ) ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    Graph g;
    ifstream ifs(argv[1]);
    g.init(ifs);
    g.print();
}
