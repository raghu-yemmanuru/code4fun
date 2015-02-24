#include <iostream>

using namespace std;
struct node {
    int data;
    node *next;
    node(int _data):data(_data){}
};

node *reverse(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *current = head;
    node *prev = NULL;
    node *next = NULL;
    while (current->next) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    current->next = prev;
    return current;
}

node *findMid(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *slow,*fast;
    slow = fast = head;
    while (slow && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
        
void printList(node *head) {
    node *current = head;
    while(current) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << endl;
}

node *foldIt(node *head) {
    if (head == NULL) {
        return head;
    }
    node *mid = findMid(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    right = reverse(right);
    printList(left);
    printList(right);
    node *tmp1,*tmp2;
    while(left && right) {
        tmp1 = left->next;
        tmp2 = right->next;
        left->next = right;
        right->next = tmp1;
        left = tmp1;
        right = tmp2;
    }

    return head;
}

int main() {
    int num;
    node *head = NULL,*current = NULL;
    while (cin >> num) {
        if (head == NULL) {
            head = current = new node(num);
        } else {
            current->next = new node(num);
            current = current->next;
        }
    }
    //printList(head);
    foldIt(head);
    printList(head);
}

