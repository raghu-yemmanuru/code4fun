#include <iostream>

using namespace std;
struct node {
    int data;
    struct node *next;
    node(int _data):data(_data) {}
};
typedef struct node Node;

Node *reverse_k(Node *header, int k) {
    Node *start = header;
    Node *ptr1 = NULL;
    Node *ptr2 = NULL;
    Node *end = NULL;
    Node dummy;
    dummy.next = header;
    while (start) {
        int c = k;
        end = start;
        ptr1 = start;
        while (end && --c) {
            ptr2 = ptr2->next;
        }
        while (ptr1 != ptr2) {
            Node *nextPtr = ptr1->next;
            if (nextPtr) {
                nextPtr->next = ptr1;
                ptr1 = nextPtr;
            }
        }
        start = ptr1->next;
    }

                

    in
int main() {
    int k = 3;
    Node *header = new Node(1);
    Node *ptr = header;
    for (int i = 0; i < 8; i++) { 
        ptr->next = new Node(i+2);
        ptr = ptr->next;
    }
    reverse_k(header,k);
}

