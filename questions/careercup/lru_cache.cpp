#include <iostream>
#include <map>

using namespace std;
struct Key {
    int id;
    Key(int _id): id(_id) {}
};

struct Value {
    int val;
    Value(int _val): val(_val) {}
};

struct cacheNode {
    Key k;
    Value v;
    cacheNode *prev,*next;
    cacheNode(const Key &_k, Value _v):k(_k),v(_v),prev(NULL),next(NULL){}
};

struct NodeCompare {
    bool operator() (const Key &lhs, const Key &rhs) {
        return lhs.id < rhs.id;
    }
};

typedef map<Key,cacheNode*,NodeCompare> Map;

class LRU {
private:
    Map m;
    cacheNode *m_head;
    cacheNode *m_tail;
    int m_capacity;
    void deleteCacheNode(cacheNode *);
    void moveTop(cacheNode *);
public:
    LRU(int _c = 2):m_capacity(_c),m_head(NULL),m_tail(NULL){}
    void set(Key k, Value v);
    Value get(const Key &k);

};

void LRU::moveTop(cacheNode *cur) {
    cur->next = m_head;
    m_head = cur;
    if (!m_tail) {
        m_tail = cur;
    }
    m.insert(make_pair(cur->k,cur));

    return;
}

void LRU::deleteCacheNode(cacheNode *cur) {
    if (!cur) {
        return;
    }

    cacheNode *prev = cur->prev;
    cacheNode *next = cur->next;
    if (prev) {
        prev->next = next;
    }
    if (next) {
        next->prev = prev;
    }
    if (m_head == cur) {
        m_head = next;
    }
    if (m_tail == cur) {
        m_tail = prev;
    }
    m.erase(cur->k);
}
    
Value LRU::get(const Key &k) {
    Map::iterator itr;
    itr = m.find(k);
    if (itr == m.end()) {
        return Value(-1);
    }
    cacheNode *cur = itr->second;
    deleteCacheNode(cur);
    moveTop(cur);

    return cur->v;
}

void LRU::set(Key k, Value _val) {
    Map::iterator itr;
    itr = m.find(k);
    if (itr != m.end()) {
        cacheNode *cur = itr->second;
        deleteCacheNode(cur);
        moveTop(cur);
        return;
    }

    cacheNode *newNode = new cacheNode (k,_val);
    moveTop(newNode);

    if (m.size() > m_capacity) {
        cacheNode *cur = m_tail;
        deleteCacheNode(cur);
        delete cur;
    }
    return;
}

int main() {
    int c;
    int k,v;
    string op;
    cin >> c;
    LRU l(c);
    while (cin >> op >> k) {
        if (op == "get") {
            cout << l.get(Key(k)).val << endl;
        } else if (op == "set") {
            cin >> v;
            l.set(Key(k),Value(v));
        }
    }
}
