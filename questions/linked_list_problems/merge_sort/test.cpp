#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

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

Node *SortedMerge (Node *a, Node *b) {
    Node dummy(-1);
    Node *current = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->data < b->data) {
            current->next = a;
            current = current->next;
            a = a->next;
        } else {
            current->next = b;
            current = current->next;
            b = b->next;
        }
    }

    if (!a) {
        current->next = b;
    } else {
        current->next = a;
    }

    return dummy.next;
}

void mergeSort(Node **headRef) {
    Node *front = NULL, *back = NULL;
    if (*headRef == NULL || (*headRef)->next == NULL) {
        return;
    }

    frontBackSplit(*headRef,&front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *headRef = SortedMerge(front,back);

    return;
}


int RandomNumber() {
    return rand() % 100;
}

int main () {
    srand(time(NULL));
    struct node * head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    int count1 = 0, count2 = 0;
    cin >> count1;
    //cin >> count2;

    /*vector<int> v1(count1), v2(count2);

    generate(v1.begin(), v1.end(), RandomNumber);
    generate(v2.begin(), v2.end(), RandomNumber);

    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),greater<int>());

    for (int i = 0; i < v1.size(); i++) {
        push(&first, v1[i]);
    }

    for (int i = 0; i < v2.size(); i++) {
        push(&second, v2[i]);
    }*/

    for (int i = 0; i < count1; i++) {
        push(&head, RandomNumber());
    }

    print_list(head);
    mergeSort(&head);
    print_list(head);
    return 0;
}

