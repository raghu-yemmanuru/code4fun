#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};

typedef vector<int> vi;
void printAll(node *root, vi &path) {
    if (!root) {
        return;
    }
    path.push_back(root->data);
    if (!root->left && !root->right) {
        copy(path.begin(),path.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        path.pop_back();
        return;
    }
    if (root->left) {
        printAll(root->left,path);
    }
    if (root->right) {
        printAll(root->right,path);
    }
    path.pop_back();
    return;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(9);
    root->left->right->right = new node(10);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vi path;
    printAll(root,path);
}
