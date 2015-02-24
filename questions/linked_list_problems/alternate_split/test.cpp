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

void alternateSplit(Node *source, Node **aRef, Node **bRef) {
    if (!source) {
        *aRef = NULL;
        *bRef = NULL;
        return;
    }

    if (source->next == NULL) {
        *aRef = source;
        *bRef = NULL;
        return;
    }

    *aRef = source;
    Node *first = *aRef;

    *bRef = source->next;
    Node *second = *bRef;

    Node *current = second->next;
    first->next = NULL;
    second->next = NULL;

    int count = 0;
    while (current) {
        if (count % 2 == 0) {
            first->next = current;
            first = current;
            current = current->next;
            first->next = NULL;
        } else {
            second ->next = current;
            second = current;
            current = current->next;
            second->next = NULL;
        }
        count++;
    }

    return;
}

int main () {
    srand(time(NULL));
    struct node * head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        push(&head, rand()%50);
    }

    print_list(head);
    alternateSplit(head, &first, &second);
    print_list(first);
    print_list(second);
    return 0;
}

