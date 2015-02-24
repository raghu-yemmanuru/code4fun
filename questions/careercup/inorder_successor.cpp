#include <iostream>

using namespace std;
struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};


node *minNode (node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
typedef pair<node*,bool> Pair;
node *tmp = NULL;

Pair inorderSuccessor(node *root, int key) {
    if (!root) {
        return make_pair(tmp,false);
    }
    if (key < root->data) {
        Pair p = inorderSuccessor(root->left,key);
        if (p.first) {
            return p;
        } else if (p.second) {
            return make_pair(root,true);
        }
            
    } else if (key > root->data) {
        return inorderSuccessor(root->right,key);
    } else { // if root is same as key
        if (root->right) {
            node *min = minNode(root->right);
            return make_pair(min,true);
        } else { // potentially on the other side of tree ?
            return make_pair(tmp,true);
        }
    }
}

int main() {
    node *root = new node(8);
    root->left = new node(4);
    root->left->left = new node(2);
    root->left->right = new node(5);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(14);

    int num;
    Pair p; 
    while (cin >> num) {
        p = inorderSuccessor(root,num);
        if (p.first) {
            cout << "Successor is " << p.first->data << endl;
        } else {
            cout << "No successor found" << endl;
        }
    }
}
