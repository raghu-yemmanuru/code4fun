#include <iostream>
#include <set>

using namespace std;
struct node {
    int data;
    node *left,*right;
    node (int _d):data(_d),left(NULL),right(NULL){}
};
typedef multiset<int> MSet;

bool traverse(node *root, MSet &s) {
    if (!root) {
        return true;
    }
    MSet::iterator itr;
    if ((itr = s.find(root->data)) == s.end()) {
        return false;
    }
    s.erase(itr);
    return (traverse(root->left,s) && traverse(root->right,s));
}

void build(node *root, MSet &s) {
    if (!root) {
        return;
    }
    s.insert(root->data);
    build(root->left,s);
    build(root->right,s);
}

bool isSame(node *root1, node *root2) {
    MSet s;
    build(root1,s);
    if (traverse(root2,s) == false) {
        return false;
    }
    if (!s.empty()) {
        return false;
    }
    return true;
}

int main() {
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(2);
    root1->right = new node(3);
    
    node *root2 = new node(3);
    root2->left = new node(2);
    root2->right = new node(1);
    root2->right->left = new node(2);
    
    if (isSame(root1,root2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
