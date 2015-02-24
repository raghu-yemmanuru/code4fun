#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *prev,*next;
    node (int _d):data(_d),prev(NULL),next(NULL){}
};

void print(node *root) {
    if (!root) {
        return;
    }
    print(root->prev);
    cout << root->data << endl;
    print(root->next);
}

node *findMiddle(node *current) {
    node *slow,*fast;
    slow = current, fast = current;
    if (!current) {
        return NULL;
    }
    while(slow->next && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *convert(node *current) {
    if (!current || !current->next) {
        return current;
    }

    node *middle = findMiddle(current);
    if (!middle) {
        cout << " ERRROR " << endl;
    }
    node *next = middle->next;
    if (middle->prev) {
        middle->prev->next = NULL;
    }
    if (next) {
        next->prev = NULL;
    }
    if (middle != current) {
        middle->prev = convert(current);
    }
    middle->next = convert(next);
    return middle;
}


int main() {
    node *head = new node(1);
    node *current = head;
    for (int i = 2; i < 7; i++) {
        node *tmp = new node(i);
        current->next = tmp;
        tmp->prev = current;
        current = tmp;
    }

    node *root = convert(head);
    print(root);
}

