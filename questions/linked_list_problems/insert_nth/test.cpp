#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data): data(_data) {}
};
typedef struct node Node;

void insertNth(Node **headref, int index, int value) {
    Node *current = *headref;
    Node *prev = NULL;

    if (index == 0) {
        Node *newNode = new Node(value);
        newNode->next = current;
        *headref = newNode;
        return;
    }

    while (current && index--) {
        prev = current;
        current = current->next;
    }

    if (!current && index > 0) {
        cout << "Failed to insert " << endl;
        return;
    }

    Node *newNode = new Node(value);
    prev->next = newNode;
    newNode->next = current;

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

int main () {
    struct node * head = NULL;
    insertNth(&head, 0, 13);
    insertNth(&head, 1, 42);
    insertNth(&head, 1, 5);

    print_list(head);
    return 0;
}

