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

Node *sortedIntersect(Node *a, Node *b) {
    Node dummy(-1);
    Node *current = &dummy;
    dummy.next = NULL;

    int val = 0;

    while (a && b) {
        if (a->data < b->data) {
            val = a->data;
            a = a->next;
        } else if (a->data > b->data){
            val = b->data;
            b = b->next;
        } else {
            val = a->data;
        }
        current->next = new Node(val);
        current = current->next;
        while (a && a->data == val) {
            a = a->next;
        }
        while (b && b->data == val) {
            b = b->next;
        }
    }
    while (a) {
        current->next = new Node(a->data);
        current = current->next;
        a = a->next;
    }
    while(b) {
        current->next = new Node(b->data);
        current = current->next;
        b = b->next;
    }
    return dummy.next;
}

void push(Node **headRef, int data) {
    Node *newNode = new Node(data);
    newNode->next = *headRef;
    *headRef = newNode;
    return;
}

int random_number() {
    return rand()%10;
}

int main () {
    srand(time(NULL));
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    int count1 = 0, count2 = 0;
    cin >> count1;
    cin >> count2;
    vector<int> v1(count1);
    vector<int> v2(count2);

    generate(v1.begin(),v1.end(),random_number);
    generate(v2.begin(),v2.end(),random_number);
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),greater<int>());

    for (int i = 0; i < v1.size(); i++) {
        push(&first, v1[i]);
    }
    for (int i = 0; i < v2.size(); i++) {
        push(&second, v2[i]);
    }

    print_list(first);
    print_list(second);
    head = sortedIntersect(first,second);
    print_list(head);
    return 0;
}

