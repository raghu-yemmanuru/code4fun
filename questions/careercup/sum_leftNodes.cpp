#include <iostream>
#include <string>

using namespace std;

struct node {
    int data;
    node *left,*right;
    node (int _data):data(_data),left(NULL),right(NULL){}
};

int update(node *root, int sum) {
    if (!root) {
        return 0;
    }
    int val1 = update(root->left,sum);
    int curData = root->data;
    root->data = root->data + val1 + sum;
    int val2 = update(root->right,root->data);

    return (curData + val1 + val2);
}

void print(node *root) {
    if (!root) {
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    //root->right->left = new node(4);

    update(root,0);
    print(root);
    cout << endl;
}

