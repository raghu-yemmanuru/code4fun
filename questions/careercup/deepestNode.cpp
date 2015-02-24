#include <iostream>
#include <vector>

using namespace std;
struct node {
    char data;
    node *left,*right;
    node (char _c):data(_c),left(NULL),right(NULL){}
};

typedef pair<node*,int> Pair;
node *nullPtr = NULL;

Pair deepestNode(node *root) {
    if (!root) {
        return make_pair(nullPtr,-1);
    }
    Pair p1 = deepestNode(root->left);
    Pair p2 = deepestNode(root->right);

    if (p1.first == NULL && p2.first == NULL) {
        return make_pair(root,1);
    } else if (p1.first == NULL) {
        return make_pair(p2.first,p2.second+1);
    } else if (p2.first == NULL) {
        return make_pair(p1.first,p1.second+1);
    } else {
        if (p1.second > p2.second) {
            return make_pair(p1.first,p1.second+1);
        } else {
            return make_pair(p2.first,p2.second+1);
        }
    }
}

int main() {
    node *root = new node('A');
    root->left = new node('B');
    root->right = new node('C');
    root->left->left = new node('D');
    root->left->left->right = new node('H');
    root->left->right = new node('E');
    root->right->left = new node('F');
    root->right->right = new node('G');

    Pair p = deepestNode(root);
    if (p.first) {
        cout << p.first->data << endl;
    } else {
        cout << "No node" << endl;
    }
}
