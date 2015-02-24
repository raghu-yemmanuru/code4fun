#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef map<string,string> MapS;
typedef map<string,bool> MapB;
typedef map<int,string> MapI;
typedef set<string> Set;

int visited_time = 0;
void dfs(string src, MapI &counts, MapB &visited, MapS &m) {
    if (visited[src]) {
        return;
    }
    visited[src] = true;
    if (m.find(src) != m.end()) {
        dfs(m[src],counts,visited,m);
    }
    counts[++visited_time] = src;
}

void extract(MapS &m, Set &s) {
    MapB visited;
    MapI counts;

    for (Set::iterator itr = s.begin(); itr != s.end(); itr++) {
        if (visited[*itr] == false) {
            dfs(*itr,counts,visited,m);
        }
    }

    for (MapI::reverse_iterator itr = counts.rbegin(); itr != counts.rend(); itr++) {
        cout << itr->second << " ";
    }
    cout << endl;
}
    
int main() {
    string src,dst;
    MapS m;
    Set s;
    while(cin >> src >> dst) {
        m[src] = dst;
        s.insert(src);
        s.insert(dst);
    }
    extract(m,s);
}
