#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef pair<int,int> cell;

int total = 0;

bool find_freecell(vvi &G, cell &F) {
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G[i].size(); j++) {
            if (!G[i][j]) {
                F.first = i;
                F.second = j;
                return true;
            }
        }
    }

    return false;
}

bool safe(vvi &G, cell P,int val) {
    int row = P.first;
    int col = P.second;
    for (int i = 0; i < G.size(); i++) {
        if (G[i][col] == val) {
            return false;
        }
    }

    for (int i = 0; i < G[row].size(); i++) {
        if (G[row][i] == val) {
            return false;
        }
    }

    int sr = row-(row%2);
    int sc = col-(col%2);
    for (int i = sr; i < sr+2; i++) {
        for (int j = sc; j < sc+2; j++) {
            if (G[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}
    
void printG(vvi &G) {
    cout << "Solution " << ++total << endl;
    cout << "--------" << endl;
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G[i].size(); j++) {
            cout << G[i][j] << "\t";
        }
        cout << endl;
    }
}
    

bool solve(vvi &G) {
    cell free;

    if (!find_freecell(G,free)) {
        return true;
    }
        
    for (int i = 1; i <= 4; i++) {
        if (safe(G,free,i)) {
            G[free.first][free.second] = i;
            bool val = solve(G);
            if (val ) {
                printG(G);
            }
            G[free.first][free.second] = 0;
        }
    }

    return false;
}


int main() {
    vvi G(4,vi(4,0)); 
    solve(G);
}
