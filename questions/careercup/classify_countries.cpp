#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<bool> vb;
typedef vector<vb > vvb;

void dfs(const vvi &G, int r, int c, vvb &visited) {
    if (r < 0 || r >= G.size() || c < 0 || c >= G[r].size() || G[r][c] != 1 || visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            dfs(G,r+i,c+j,visited);
        }
    }
}

int countries(const vvi &G) {
    int count = 0;
    vvb visited(G.size(),vb(G[0].size(),false));
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G[i].size(); j++) {
            if (!visited[i][j] && G[i][j] == 1) {
                count++;
                dfs(G,i,j,visited);
            }
        }
    }
    return count;
}

int main(int argc, char **argv) {
    ifstream ifs(argv[1]);
    int r, c;
    ifs >> r >> c;
    vvi G(r,vi(c,0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ifs >> G[i][j];
        }
    }
    
    cout << "Total Countries " << countries(G) << endl;
}
