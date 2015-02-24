#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data): data(_data) {}
};
typedef struct node Node;

void sortedInsert(Node **headRef, Node *newNode) {

    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    Node *current = *headRef;
    while (current->next && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return;
}

void insertSort(Node **headRef) {
    Node *current = *headRef;
    Node *next;

    if (!current) {
        return;
    }

    next = current->next;
    current->next = NULL;
    current = next;

    while(current) {
        next = current->next;
        current->next = NULL;
        sortedInsert(headRef, current);
        current = next;
    }

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
    srand(time(NULL));
    struct node * head = NULL;
    for (int i = 0; i < 10; i++) {
        push(&head, rand()%100);
    }
    /*push(&head, 10);
    push(&head, 5);
    push(&head, 1);*/

    insertSort(&head);

    print_list(head);
    return 0;
}

