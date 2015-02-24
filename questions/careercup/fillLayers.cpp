#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;

void fillLayer(vvi &G, int x1, int x2, int y1, int y2, int &count) {
    for (int i = y1; i <= y2; i++) {
        G[x1][i] = count++;
    }
    for (int i = x1+1; i <= x2; i++) {
        G[i][y2] = count++;
    }
    if (x1 != x2) {
        for (int i = y2-1; i >= y1; i--) {
            G[x2][i] = count++;
        }
    }

    if (y1 != y2) {
        for (int i = x2-1; i > x1; i--) {
            G[i][y1] = count++;
        }
    }
}
    
void fill(vvi &G) {
    int i = 0, j = G.size()-1, k = 0, l = G[0].size()-1;
    int count = 1;
    while(i <= j && k <= l) {
        fillLayer(G,i,j,k,l,count);
        cout << "Count is " << count << endl;
        i++;
        j--;
        k++;
        l--;
    }
}

int main() {
    int m,n;
    cin >> m >> n;
    vvi G(m,vi(n,-1));
    fill(G);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << G[i][j] << "\t";
        }
        cout << endl;
    }
}


