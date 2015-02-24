#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data): data(_data) {}
};
typedef struct node Node;


void print_list(Node *root) {
    Node *current = root;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node *reverse_list(Node *root) {
    Node *prev = NULL;
    Node *current = root;
    Node *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *reverse_k_list(Node *root, int k) {
    if (!root) {
        return NULL;
    }

    Node *prev = NULL;
    Node *current = root;
    Node *next = NULL;
    int newK = k;

    while (current && newK--) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    Node *k_list = reverse_k_list(current, k);
    root->next = k_list;
    return prev;
}

int main () {
    Node *root = new Node(1);
    Node *current = root;

    for (int i = 2; i < 8; i++) {
        current->next = new Node(i);
        current = current->next;
    }

    /*print_list(root);
    Node *rRoot = reverse_list(root);
    print_list(rRoot);*/

    print_list(root);
    Node *kReverse = reverse_k_list(root,3);
    print_list(kReverse);
    return 0;
}
