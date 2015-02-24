#include <iostream>
#include <queue>

using namespace std;

struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};

void levelPrint(node *root) {
    queue<node *> current_level, next_level;
    node *tmp;
    if (!root) {
        return;
    }
    current_level.push(root);
    while (true) {
        while(!current_level.empty()) {
            tmp = current_level.front();
            cout << tmp->data << " ";
            if (tmp->left) {
                next_level.push(tmp->left);
            }
            if (tmp->right) {
                next_level.push(tmp->right);
            }
            current_level.pop();
        }
        cout << endl;
        swap(current_level,next_level);
        if (current_level.empty()) 
            break;
    }
}

int main () {
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->left->left->left = new node(5);
    root->right = new node(3);
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    levelPrint(root);
}
