#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
enum color_t {WHITE=0,GREY,BLACK};
typedef vector<string> vs;
typedef map<string,vs > Map;
typedef map<string,color_t> Mapc;

bool dfs(const string &u, Map &m, Mapc &colors) {
    colors[u] = GREY;
    if (m.find(u) != m.end()) {
        for (int i = 0; i < m[u].size(); i++) {
            if (colors[m[u][i]] == GREY) {
                return true;
            }
            if (colors[m[u][i]] == WHITE) {
                if (dfs(m[u][i],m,colors)) {
                    return true;
                }
            }
        }
    }
    colors[u] = BLACK;
    return false;
}

bool hasCycle(Map &m) {
    Mapc colors; 
    for (Map::iterator itr = m.begin(); itr != m.end(); itr++) {
        if (colors[itr->first] == WHITE) {
            if (dfs(itr->first,m,colors)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string p1,p2,orientation;
    Map clock,anti;
    while(cin >> orientation >> p1 >> p2) {
        if (orientation == "clock") {
            clock[p1].push_back(p2);
            anti[p2].push_back(p1);
        } else {
            anti[p1].push_back(p2);
            clock[p2].push_back(p1);
        }
    }

    if (hasCycle(clock)) {
        cout << "Not possible" << endl;
    } else {
        cout << "Possible" << endl;
    }
    /*|| hasCycle(anti)) {
        cout << "Not possible" << endl;
    } else {
        cout << "possible" << endl;
    }*/
}
