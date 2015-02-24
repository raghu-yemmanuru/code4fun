#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<bool> vb;
typedef vector<vb > vvb;

void traverse(vvi &v, int r, int c, vvb &visited, int num) {
    if (r < 0 || r >= v.size() || c < 0 || c >= v[0].size() || visited[r][c] || v[r][c] != num) {
        return;
    }
    visited[r][c] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            traverse(v,r+i,c+j,visited,num);
        }
    }
    return;
}
            

int totalCountries(vvi &v) {
    vvb visited(v.size(),vb(v[0].size(),false));
    int countries = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (!visited[i][j]) {
                ++countries;
                traverse(v,i,j,visited,v[i][j]);
            }
        }
    }

    return countries;
}

int main(int argc, char **argv) {
    int m,n;
    ifstream ifs(argv[1]);
    ifs >> m >> n;
    vvi v(m,vi(n,-1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ifs >> v[i][j];
        }
    }

    cout << "Total Countries " << totalCountries(v) << endl;
}
