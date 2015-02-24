#include <iostream>
#include <vector>

using namespace std;
struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};
typedef pair<node*,int> Pair;
node *tmp = NULL;
node *LCA1(node *root, int n1, int n2) {
    if (!root) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    node *l_lca = LCA1(root->left,n1,n2);
    node *r_lca = LCA1(root->right,n1,n2);
    if (l_lca && r_lca) {
        return root;
    }
    if (l_lca) {
        return l_lca;
    } else {
        return r_lca;
    }
}

Pair LCA(node *root, int n1, int n2) {
    if (!root) {
        return make_pair(tmp,0);
    }
    Pair p1 = LCA(root->left,n1,n2);
    Pair p2 = LCA(root->right,n1,n2);
    if (p1.first) {
        return make_pair(p1.first,2);
    }
    if (p2.first) {
        return make_pair(p2.first,2);
    }
    int count = p1.second + p2.second;
    if (count == 2) {
        return make_pair(root,2);
    }
    if (count == 1) {
        if (root->data == n1 || root->data == n2) {
            return make_pair(root,2);
        }
        return make_pair(tmp,1);
    }
    if (root->data == n1 || root->data == n2) {
        return make_pair(tmp,1);
    }
    return make_pair(tmp,0);
}

        
int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    int num1,num2;
    Pair p;
    node *dummy;
    while(cin >> num1 >> num2) {
        p = LCA(root,num1,num2);
        if (p.first) {
            cout << "LCA is " << p.first->data << endl;
        } else {
            cout << "No LCA found" << endl;
        }
        dummy = LCA1(root,num1,num2);
        if (dummy) {
            cout << "LCA is " << dummy->data << endl;
        } else {
            cout << "No LCA found!!!" << endl;
        }
    }
    return 0;
}
