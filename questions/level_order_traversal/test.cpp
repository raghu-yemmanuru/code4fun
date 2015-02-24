#include <iostream>
#include <queue>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int _data):data(_data) {}
};
typedef struct node Node;
void level_order_print(Node *root) {
    queue<Node*> c, n;
    int level = 0;
    if (!root) {
        return;
    }

    c.push(root);
    do {
        level++;
        cout << "Level " << level << "==>  ";
        while (!c.empty()) {
            Node *tmp = c.front();
            c.pop();
            if (tmp->left) n.push(tmp->left);
            if (tmp->right) n.push(tmp->right);
            /*if (tmp->data == key) {
                    cout << "right node of " << key << " is ";
                if (c.size()) {
                    cout << c.back()->data << endl;
                } else {
                    cout<< "NULL" << endl;
                }
                return;
            }*/
            cout << tmp->data << " ";
        }
        cout << endl;
        swap(c,n);
    } while (!c.empty());
}

Node *buildTree() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return root;
}

int main() {
    Node *root = buildTree();
    level_order_print(root);
}
