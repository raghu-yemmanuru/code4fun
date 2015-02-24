#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node *left,*right;
    node(int _d):data(_d),left(NULL),right(NULL){}
};

typedef pair<node*,node*> Pair;
node *nullPtr= NULL;

Pair convertToDll(node *root) {
    if (!root || (!root->left && !root->right)) {
        return make_pair(root,root);
    }
    Pair p1 = convertToDll(root->left);
    Pair p2 = convertToDll(root->right);
    if (p1.second) {
        p1.second->right = root;
        root->left = p1.second;
    }
    if (p2.first) {
        p2.first->left = root;
        root->right = p2.first;
    }
    return make_pair(p1.first?p1.first:root,p2.second?p2.second:root);
}

Pair convert(node *root) {
    if (!root) {
        return make_pair(root,root);
    }
    Pair p = convertToDll(root);
    p.first->left = p.second;
    p.second->right = p.first;
    return p;
}

void print(node *head) {
    node *current = head;
    if (!head) {
        return;
    }
    do {
        cout << head->data << " ";
        head = head->right;
    } while(head != current);
    cout << endl;
    return;
}

int main() {
    node *root = new node(8);
    root->left = new node(4);
    root->left->left = new node(3);
    root->left->left->left = new node(2);
    root->left->right = new node(5);
    root->right = new node(9);
    root->right->left = new node(11);
    root->right->right = new node(12);

    Pair p = convert(root);
    print(p.first);
}
