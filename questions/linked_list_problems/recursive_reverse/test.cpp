#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data): data(_data),
                     next(NULL)
    {}
};
typedef struct node Node;


void print_list (Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void push(Node **headRef, int data) {
    Node *newNode = new Node(data);
    newNode->next = *headRef;
    *headRef = newNode;
    return;
}

int random_number() {
    return rand()%100;
}

/*void reverse(Node **headRef, Node **tailRef) {
    if (*headRef == NULL) {
        *tailRef = NULL;
        return;
    }

    if ((*headRef)->next == NULL) {
        *tailRef = *headRef;
        return;
    }

    reverse(&((*headRef)->next), tailRef);
    (*tailRef)->next = *headRef;
    *tailRef = *headRef;
    *headRef = (*headRef)->next;
    (*tailRef)->next = NULL;

    return;
}
void recursiveReverse(Node **headRef) {
    Node *dummyTail = NULL;
    reverse(headRef,&dummyTail);
    return;
}*/

void recursiveReverse(Node **headRef) {
    Node *first;
    Node *rest;

    if (*headRef == NULL || (*headRef)->next == NULL) {
        return;
    }

    first = *headRef;
    rest = (*headRef)->next;

    recursiveReverse(&rest);
    first->next->next = first;
    first->next = NULL;

    *headRef = rest;
    return;
}

int main () {
    srand(time(NULL));
    Node *head = NULL;
    int count = 0;
    cin >> count;
    vector<int> v1(count);

    generate(v1.begin(),v1.end(),random_number);

    for (int i = 0; i < v1.size(); i++) {
        push(&head, v1[i]);
    }
    print_list(head);
    recursiveReverse(&head);
    print_list(head);
    return 0;
}

