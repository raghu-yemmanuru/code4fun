#include <iostream>
#include <queue>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int _data):data(_data),left(NULL),right(NULL) {}
};

void level_order_print(node *root) {
    if (!root) {
        return;
    }

    queue<node *> *current_level, *next_level;
    current_level = new queue<node *>();
    next_level = new queue<node *>();

    current_level->push(root);
    do {
        while (!current_level->empty()) {
            node *cur = current_level->front();
            cout << cur->data << " ";

            if (cur->left) {
                next_level->push(cur->left);
            }
            if (cur->right) {
                next_level->push(cur->right);
            }
            current_level->pop();
        }
        cout << endl;
        swap(current_level,next_level);
    } while (!current_level->empty());
    delete current_level;
    delete next_level;
}

node *buildTree() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    return root;
}

int main() {
    node *root = buildTree();
    level_order_print(root);
}
