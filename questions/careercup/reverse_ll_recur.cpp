#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *next;
    node(int _data):data(_data),next(NULL){}
};

node *insert(node *head, int num) {
    node *tmp = new node(num);
    tmp->next = head;
    head = tmp;
    return head;
}

node *reverse_recur(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *r_head = reverse_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return r_head;
}

void print(node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
    
int main() {
    int num;
    node *head = NULL;
    while(cin >> num) {
        head = insert(head,num);
    }
    print(head);
    node *r_head = reverse_recur(head);
    print(r_head);
}
