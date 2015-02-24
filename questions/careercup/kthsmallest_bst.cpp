#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};

void printKthsmallest(node *root, int k, int &count) {
    if (!root) {
        return;
    }
    printKthsmallest(root->left,k,count);
    if (count == k) {
        cout << "Value is " << root->data << endl;
        ++count;
        return;
    }
    ++count;
    printKthsmallest(root->right,k,count);
}


int main() {
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->right = new node(4);
    root->right = new node(6);
    root->right->right = new node(8);
    root->right->right->left = new node(7);
    root->right->right->right = new node(9);

    int k;
    int count = 0;
    while (cin >> k) {
        count = 0;
        printKthsmallest(root,k,count);
    }
}
