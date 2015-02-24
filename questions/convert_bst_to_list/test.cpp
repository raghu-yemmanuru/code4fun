#include <iostream>
using namespace std;
struct node {
    string val;
    node *left,*right;
    node(string _val):val(_val),left(NULL),right(NULL){}
};
typedef pair<node*,node*> Pair;

Pair convert(node *root) {
    if (!root) {
        return make_pair(root,root);
    }
    Pair p1 = convert(root->left);
    Pair p2 = convert(root->right);

    root->left = p1.second;
    if (p1.second) {
        p1.second->right = root;
    }

    root->right = p2.first;
    if (p2.first) {
        p2.first->left = root;
    }

    return make_pair(p1.first?p1.first:root, p2.second?p2.second:root);
}

int main() {
    node *root = new node("d");
    root->left = new node("b");
    root->left->left = new node("a");
    root->left->right = new node("c");
    root->right = new node("e");
    Pair p = convert(root);
    node *current = p.first;
    while (current) {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;
    current = p.second;
    while (current) {
        cout << current->val << " ";
        current = current->left;
    }
    cout << endl;
}
