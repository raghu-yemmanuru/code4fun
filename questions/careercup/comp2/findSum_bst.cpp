#include <iostream>
#include <vector>

using namespace std;
struct node {
    int data;
    node *left,*right;
    node(int _d):data(_d),left(NULL),right(NULL){}
};

bool treeSearch(node *root, int val) {
    if (!root) {
        return false;
    }
    if (root->data == val) {
        return true;
    }
    if (val < root->data) {
        return treeSearch(root->left,val);
    } else {
        return treeSearch(root->right,val);
    }
}

bool sumPossible (node *root, node *treeRoot, int sum) {
    if (!root) {
        return false;
    }
    int val = sum - root->data;
    if (treeSearch(treeRoot,val)) {
        return true;
    }
    return sumPossible(root->left,treeRoot,sum) || sumPossible(root->right,treeRoot,sum);
}

int main() {
    node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(7);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(22);

    int sum;
    while(cin >> sum) {
        if (sumPossible(root,root,sum)) {
            cout << "Can be made" << endl;
        } else {
            cout << "Sorry" << endl;
        }
    }
}
