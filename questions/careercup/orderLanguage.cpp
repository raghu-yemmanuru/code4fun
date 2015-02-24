#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <stack>

using namespace std;
typedef map<char,string> Map;
typedef map<char,bool> MapB;
typedef map<int,char> MapI;
typedef vector<string> vs;


int visited_time = 0;

void traverse(char u, Map &m, MapB &visited, stack<char> &order) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = 0; i < m[u].size(); i++) {
        traverse(m[u][i],m,visited,order);
    }
    order.push(u);
    //counts[++visited_time] = u;
}

void dfs(Map &m) {
    MapB visited;
    MapI counts;
    stack<char> order;
    for (Map::iterator itr = m.begin(); itr != m.end(); itr++) {
        if (visited[itr->first] == false) {
            traverse(itr->first, m, visited,order);
        }
    }

    /*for (MapI::reverse_iterator itr = counts.rbegin(); itr != counts.rend(); itr++) {
        cout << itr->second << " ";
    }*/
    while(!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;
}

void buildMap(const string &word1, const string &word2, Map &m) {
    int i = 0, j = 0;
    while(i < word1.size() && j < word2.size()) {
        if (word1[i] != word2[i]) {
            break;
        }
        i++;j++;
    }
    if (i == word1.size() || j == word2.size()) {
        return;
    }
    m[word1[i]].push_back(word2[j]);
}

int main(int argc, char **argv) {
    ifstream ifs(argv[1]);
    Map m;
    vs words;
    string word;
    while(ifs >> word) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size()-1; i++) {
        buildMap(words[i],words[i+1],m);
    }
    dfs(m);
}
