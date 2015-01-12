#include <iostream>
#include <map>

using namespace std;

struct node {
    bool mark;
    map<char,node*> m;
    node(): mark(false) {}
    node *findChild(char ch) {
        map<char,node*>::iterator itr;
        itr = m.find(ch);
        if (itr == m.end()) {
            return NULL;
        }
        return itr->second;
    }
    node *addChild(char ch, node *child) {
        m[ch] = child;
    }
    void deleteChild(char ch) {
        map<char,node*>::iterator itr = m.find(ch);
        if (itr != m.end()) {
            m.erase(itr);
        }
    }
    int childrenCount() {
        return m.size();
    }
    void setMarker(bool _mark) {
        mark = _mark;
    }
    bool getMarker() {
        return mark;
    }
};

class Trie {
private:
    node *root;
public:
    Trie():root(new node()) {}
    void addWord(string s) {
        node *current = root;
        for (int i = 0; i < s.size(); i++) {
            node *child = current->findChild(s[i]);
            if (!child) {
                child = new node();
                current->addChild(s[i],child);
            }
            current = child;
        }
        current->setMarker(true);
    }
    bool searchWord(string s) {
        node *current = root;
        for (int i = 0; i < s.size(); i++) {
            node *child = current->findChild(s[i]);
            if (!child) {
                return false;
            }
            current = child;
        }
        if (current && current->getMarker()) {
            return true;
        }
        return false;
    }
    bool deleteUtil(string s, node *current) {
        if (!current) {
            return false;
        }
        if (s.size() == 0) {
            current->setMarker(false);
            return (current->childrenCount() == 0);
        }
        node *child = current->findChild(s[0]);
        if (deleteUtil(s.substr(1),child)) {
            current->deleteChild(s[0]);
            return (current->childrenCount() == 0);
        }
        return false;
    }

    void deleteWord(string s) {
        if (s.size() == 0) {
            cout << "Cant delete empty string" << endl;
            return;
        }
        deleteUtil(s,root);
    }
};

int main() {
    Trie t;
    string op, s;
    while (cin >> op >> s) {
        if (op == "add") {
            t.addWord(s);
        } else if (op == "search") {
            cout << "Search returned " << t.searchWord(s) << endl;
        } else if (op == "delete") {
            t.deleteWord(s);
        }
    }
}
