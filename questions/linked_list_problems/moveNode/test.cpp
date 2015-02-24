#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data): data(_data) {}
};
typedef struct node Node;

void push(Node **headRef, int value) {
    Node *newNode = new Node(value);
    newNode->next = *headRef;
    *headRef = newNode;

    return;
}

void print_list (Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void moveNode(Node **dRef, Node **sRef) {
    if (!(*sRef)) {
        cerr << "Error in source " << endl;
        return;
    }
    Node *current = *sRef;
    *sRef = current->next;
    current->next = *dRef;
    *dRef = current;
    return;
}
    

int main () {
    struct node * head = NULL;
    Node *d = NULL;
    Node *s = NULL;
    for (int i = 3; i > 0; i--) {
        push (&s, i);
        push (&d, i);
    }
    moveNode(&d, &s);
    print_list(d);
    print_list(s);
    return 0;
}

