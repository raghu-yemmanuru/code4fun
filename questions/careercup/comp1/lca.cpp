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

Pair LCA(node *root, int num1, int num2) {
    if (!root) {
        return make_pair(root,0);
    }

    Pair lp = LCA(root->left,num1,num2);
    Pair rp = LCA(root->right,num1,num2);

    if (lp.second == 2) {
        return lp;
    }
    if (rp.second == 2) {
        return rp;
    }

    if (lp.second + rp.second == 2) {
        return make_pair(root,2);
    }

    if (lp.second == 1 || rp.second == 1) {
        if (root->data == num1 || root->data == num2) {
            return make_pair(root,2);
        }
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
        /*dummy = LCA1(root,num1,num2);
        if (dummy) {
            cout << "LCA is " << dummy->data << endl;
        } else {
            cout << "No LCA found!!!" << endl;
        }*/
    }
    return 0;
}
