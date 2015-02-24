#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct node {
    string data;
    vector<node* > children;
    node (string _data):data(_data){}
    void addChild(node *child) {
        children.push_back(child);
    }
};

node *deserialize(string s) {
    if (s.size() == 0) {
        return NULL;
    }
    //cout << s << endl;
    int i = s.find('(',1);
    if (i == string::npos) {
        return new node(s.substr(1,s.size()-2));
    }

    node *root = new node(s.substr(1,i-1));
    int count = 0;
    int j = i;
    while (j < s.size()) {
        do {
            if (s[j] == '(') {
                count++;
            } else if (s[j] == ')') {
                count--;
            }
            j++;
        } while (j < s.size() && count != 0);
        if (j >= s.size()) {
            break;
        }
        root->addChild(deserialize(s.substr(i,j-i)));
        i = j;
        count = 0;
    }

    return root;
}

string serialize(node *root) {
    if (!root) {
        return "";
    }
    stringstream ss;
    ss << "(";
    ss << root->data;
    for (int i = 0; i < root->children.size(); i++) {
        ss << serialize(root->children[i]);
    }
    ss << ")";

    return ss.str();
}

int main() {
    node *root = new node("hello");
    node *b1 = new node("world");
    node *b2 = new node("b2");
    node *c1 = new node("c1");
    node *c2 = new node("c2");
    node *c3 = new node("c3");
    node *b = new node("b");
    node *c = new node("c");

    b->addChild(b1);
    b->addChild(b2);

    c->addChild(c1);
    c->addChild(c2);
    c->addChild(c3);

    root->addChild(b);
    root->addChild(c);

    /*cout << serialize(root) << endl;
    node *tmpRoot = deserialize(serialize(root));
    cout << serialize(tmpRoot) << endl;*/
    cout << serialize(deserialize(serialize(root))) << endl;
}
