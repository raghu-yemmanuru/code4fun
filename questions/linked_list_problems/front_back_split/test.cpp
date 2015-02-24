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

void frontBackSplit(Node *source, Node **fRef, Node **bRef) {
    *fRef = source;
    Node *current = source;
    int count = 0;
    while (current) {
        count++;
        current = current->next;
    }

    if (count == 0) {
        *fRef = NULL;
        *bRef = NULL;
        return;
    }

    int f = count/2 + count%2;
    int b  = count - f;

    current = source;
    for (int i = 0; i < f-1; i++) {
        current = current->next;
    }

    *bRef = current->next;
    current->next = NULL;
    return;
}

int main () {
    struct node * head = NULL;
    Node *fRef = NULL, *bRef = NULL;
    srand(time(NULL));
    for (int i = 0; i < 0; i++) {
        push(&head, rand()%100);
    }

    print_list(head);
    frontBackSplit(head, &fRef, &bRef);
    print_list(fRef);
    print_list(bRef);
    return 0;
}

