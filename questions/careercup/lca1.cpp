#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    char data;
    node *left,*right,*parent;
    node(char _data,node *_parent = NULL):data(_data),left(NULL),right(NULL),parent(_parent){}
};

node *LCA(node *a, node *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    vector<node *> path1,path2;
    while(a != NULL) {
        path1.push_back(a);
        a = a->parent;
    }
    while(b != NULL) {
        path2.push_back(b);
        b = b->parent;
    }

    reverse(path1.begin(),path1.end());
    reverse(path2.begin(),path2.end());

    if (path1[0] != path2[0]) {
        return NULL;
    }
    int i = 1, j = 1;
    while(i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
        i++;j++;
    }
    return path1[i-1];
}

int main() {
    node *root = new node('a');
    root->left = new node('b',root);
    root->left->left = new node('d',root->left);
    root->right = new node('c',root);
    root->right->left = new node('e',root->right);
    root->right->right = new node('f',root->right);
    map<char,node*> M;

    M['a'] = root;
    M['b'] = root->left;
    M['c'] = root->right;
    M['d'] = root->left->left;
    M['e'] = root->right->left;
    M['f'] = root->right->right;

    node *root1 = new node('j');
    root1->left = new node('h',root1);
    M['j'] = root1;
    M['h'] = root1->left;

    char ch1,ch2;
    node *lca;
    while (cin >> ch1 >> ch2) {
        lca = LCA(M[ch1],M[ch2]);
        if (!lca) {
            cout << "No LCA FOUND" << endl;
        } else {
            cout << lca->data << endl;
        }
    }
}
    
