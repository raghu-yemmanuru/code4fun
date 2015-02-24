#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;
struct node;
typedef map<char,node*> Map;
struct node {
    char m_ch;
    Map m_map;
    node *left,*right;
    int m_total;
    bool m_marker;
    vector<string> m_v;
    node(char _ch):m_ch(_ch),m_marker(false),left(NULL),right(NULL),m_total(0){};
    void setMarker(bool _marker) {
        m_marker = _marker;
        m_total++;
    }
    bool getMarker() {
        return m_marker;
    }
    node *findChild(char _ch) {
        if (m_map.find(_ch) == m_map.end()) {
            return NULL;
        }
        return m_map[_ch];
    }
    void addChild(char ch, node *child) {
        m_map[ch] = child;
        return;
    }
};

class Trie {
private:
    node *m_root;
public:
    Trie():m_root(new node(' ')){}
    void addWord(const string &s) {
        string ss = s;
        sort(ss.begin(),ss.end());
        node *current = m_root;
        node *child;
        for(int i = 0; i < ss.size(); i++) {
            child = current->findChild(ss[i]);
            if (!child) {
                child = new node(ss[i]);
                current->addChild(ss[i],child);
            }
            current = child;
        }
        current->setMarker(true);
        current->m_v.push_back(s);
    }
    bool searchWord(const string &s) {
        node *current = m_root;
        node *child;
        for (int i = 0; i < s.size() && current; i++) {
            child = current->findChild(s[i]);
            current = child;
        }
        if (current && current->getMarker()) {
            return true;
        }
        return false;
    }
    void anagramUtil(node *root, string s) {
        if (!root) {
            return;
        }
        if (root->getMarker()) {
            cout << "Anagrams of " << s << endl;
            copy(root->m_v.begin(),root->m_v.end(),ostream_iterator<string>(cout," "));
            cout << endl;
        }
        for (Map::iterator itr = root->m_map.begin(); itr != root->m_map.end(); itr++) {
            anagramUtil(itr->second,s+(itr->first));
        }
    }

    void printAllAnagrams() {
        anagramUtil(m_root,"");
    }
};

int main() {
    string word;
    Trie T;

    while(cin >> word) {
        T.addWord(word);
    }
    T.printAllAnagrams();
}
