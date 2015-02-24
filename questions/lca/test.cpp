#include <iostream>
using namespace std;

struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL) {}
};

int find(node *root, int k1, int k2, node *& lca) {
    if (root == NULL) {
        return 0;
    }

    int left = find(root->left,k1,k2,lca);
    int right = find(root->right,k1,k2,lca);
    int present = 0;

    if (root->data == k1 || root->data == k2) {
        present = 1;
        if (left == 1 || right == 1) {
            lca = root;
        }
    }

    if (left == 1 && right == 1) {
        lca = root;
    }

    return (left + right + present);
}

node *LCA(node *root, int k1,int k2) {
    node *lca = NULL;
    find(root,k1,k2,lca);
    if (lca) {
        cout << lca->data << endl;
    } else {
        cout << "No LCA found" << endl;
    }
    return lca;
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    LCA(root,4,5);
    LCA(root,4,6);
    LCA(root,3,4);
    LCA(root,2,4);
    LCA(root,2,6);
    LCA(root,2,8);

    //cout << LCA(root,4,5) << endl;
}
