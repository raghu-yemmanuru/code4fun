#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data): data(_data) {}
};
typedef struct node Node;

void sortedInsert(Node **headRef, Node *newNode) {
    Node *prev = NULL;
    Node *current = *headRef;

    while (current) {
        if (current->data >= newNode->data) {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = newNode;
    } else {
        *headRef = newNode;
    }
    newNode->next = current;

    return;
}

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

int main () {
    struct node * head = NULL;
    /*push(&head, 10);*/
    //push(&head, 5);
    push(&head, 1);

    sortedInsert(&head, new Node(4));

    print_list(head);
    return 0;
}

