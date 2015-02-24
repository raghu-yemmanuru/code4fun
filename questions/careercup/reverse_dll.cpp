#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    node *next, *prev;
    node(int _data):data(_data),next(NULL),prev(NULL){}
};

node *reverse1(node *head) {
    if (!head || !head->next) {
        return head;
    }
    node *prev = NULL;
    node *next;
    node *current = head;
    while(current) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    return prev;
}

node *reverse(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *current = head;
    node *prev;
    while(current) {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        current = current->prev;
    }
    return prev->prev;

}

node* insert(node *head, int num) {
    node *tmp = new node(num);
    tmp->next = head;
    head->prev = tmp;
    return tmp;
}

void print(node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    node *head = new node(5);
    for (int i = 0; i < 10; i++) {
        head = insert(head,rand()%20);
    }
    print(head);
    head = reverse1(head);
    print(head);
}
