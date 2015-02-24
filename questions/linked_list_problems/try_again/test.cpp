#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
typedef vector<int> vi;

struct node {
    int data;
    node *next;
    node(int _data):data(_data),next(NULL){}
};

void print(node *current) {
    while (current) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << endl;
}

void pushHead(node *&current, int num) {
    node *newNode = new node(num);
    newNode->next = current;
    current = newNode;
    return;
}

void pushTail(node *& head, int num) {
    node *newNode = new node(num);
    if (!head) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node *current = head;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
    return;
}

void append(node *&head, vi &v) {
    node *tail = head;
    int i = 0;
    if (!head) {
        head = new node(v[i++]);
        tail = head;
    } else {
        while (tail && tail->next) {
        tail = tail->next;
        }
    }

    for (; i < v.size(); i++) {
        tail->next = new node(v[i]);
        tail = tail->next;
    }
}

int count(node *head, int num) {
    node *current = head;
    int count = 0;
    while (current) {
        if(current->data == num) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int getNth(node *head, int idx) {
    node *current = head;
    int i;
    for (i = 0; i < idx && current; i++) {
        current = current->next;
    }
    if (!current || i != idx) {
        cout << "Sorry out of range..." << endl;
        return -1;
    }
    return current->data;
}

void deleteList(node *&head) {
    node *current = head;
    if (!current) {
        return;
    }
    node *next;
    while(current) {
        next = current->next;
        delete current;
        current = next;
    }
    head = current;
}

void pop(node *&head) {
    if (!head) {
        cout << "Can not pop the empty list " << endl;
        return;
    }
    node *current = head;
    head = head->next;
    current->next = NULL;
    delete current;
    return;
}

void insertNth(node *&head, int idx, int num) {
    if (idx == 0) {
        node *newNode = new node(num);
        newNode->next = head;
        head = newNode;
        return;
    }

    int i;
    node *current = head;
    for (i = 0; i < idx -1 && current; i++) {
        current = current->next;
    }
    if (!current || i != idx-1) {
        cout << "Error in request " << endl;
        return;
    }
    node *newNode = new node(num);
    newNode->next = current->next;
    current->next = newNode;

    return;
}

void sortedInsert(node *&head, node *tmp) {
    if(!head || head == tmp) {
        head = tmp;
        return;
    }

    if (head->data >= tmp->data) {
        tmp->next = head;
        head = tmp;
        return;
    }

    node *prev = head;
    node *current = prev->next;
    while(current && current->data < tmp->data) {
        prev = prev->next;
        current = current->next;
    }
    tmp->next = prev->next;
    prev->next = tmp;
    return;
}

void insertSort(node *&head) {
    if (!head || !head->next) {
        return;
    }

    node *current = head->next;
    head->next = NULL;
    node *next;
    while(current) {
        next = current->next;
        current->next = NULL;
        sortedInsert(head,current);
        current = next;
    }
    return;
}

void append(node *&a, node *&b) {
    if (!b || a == b) {
        return;
    }

    if (!a) {
        a = b;
        b = NULL;
        return;
    }

    node *current = a;
    while(current->next) {
        current = current->next;
    }
    current->next = b;
    b = NULL;
    return;
}

void frontBackSplit(node *&head, node *&a, node *&b) {
    if (!head) {
        a = b = NULL;
        return;
    }
    a = head;
    node *slow,*fast;
    slow = fast = head;
    while(slow->next && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    b = slow->next;
    slow->next = NULL;
    return;
}

void removeDuplicates(node *&head) {
    if (!(head && head->next)) {
        return;
    }
    node *current = head;
    node *next;
    while(current && current->next) {
        if (current->data != current->next->data) {
            current = current->next;
            continue;
        }
        next = current->next;
        current->next = next->next;
        delete next;
    }
    return;
}

//move head2's first node to head1's top
void moveNode(node *&head1, node *&head2) {
    if (!head2) {
        return;
    }
    node *current = head2;
    head2 = current->next;
    current->next = head1;
    head1 = current;
    return;
}

void alternateSplit(node *&head, node *&a, node *&b) {
    node *acurr, *bcurr;
    if (!head) {
        a = b = NULL;
        return;
    }
    acurr = a = head;
    if (!head->next) {
        b = NULL;
        return;
    }
    bcurr = b = head->next;
    head->next = NULL;

    node *current = b->next;
    b->next = NULL;

    int i = 0;
    node *tmp;
    while (current) {
        if (i%2 == 0) {
            acurr->next = current;
            acurr = acurr->next;
        } else {
            bcurr->next = current;
            bcurr = bcurr->next;
        }
        tmp = current->next;
        current->next = NULL;
        current = tmp;
        i++;
    }
}

node *shuffleMerge(node *a,node *b) {
    node *current;
    node dummy(-1);
    current = &dummy;
    if (!(a || b)) {
        return NULL;
    }
    while (a && b) {
        current->next = a;
        current = current->next;
        a = a->next;
        current->next = b;
        current = current->next;
        b = b->next;
    }

    while (a) {
        current->next = a;
        current = current->next;
        a = a->next;
    }

    while (b) {
        current->next = b;
        current = current->next;
        b = b->next;
    }
    return dummy.next;
}

node *sortedMerge(node *a, node *b) {
    node *current;
    node dummy(-1);
    current = &dummy;
    while (a && b) {
        if (a->data <= b->data) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }
    while (a) {
        current->next = a;
        a = a->next;
        current = current->next;
    }
    while (b) {
        current->next = b;
        b = b->next;
        current = current->next;
    }

    return dummy.next;
}

void mergeSort(node *&head) {
    node *a,*b;
    if (head == NULL || head->next == NULL) {
        return;
    }
    frontBackSplit(head,a,b);
    mergeSort(a);
    mergeSort(b);
    head = sortedMerge(a,b);
}

node* sortedIntersect(node *a, node *b) {
    if (!a || !b) {
        return NULL;
    }
    node dummy(-1);
    node *current = &dummy;
    while (a && b) {
        if (a->data == b->data) {
            current->next = new node(a->data);
            current = current->next;
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return dummy.next;
}

void deleteNode(node *&head, int num) {
    if (!head) {
        return;
    }
    node dummy(-1);
    dummy.next = head;
    node *current = &dummy;
    node *tmp;
    while(current->next) {
        if (current->next->data == num) {
            tmp = current->next;
            current->next = tmp->next;
            tmp->next = NULL;
            delete tmp;
        } else {
            current = current->next;
        }
    }
    head = dummy.next;
    return;
}

void reverse(node *&head) {
    if (!head || !(head->next)) {
        return;
    }
    node *current = head;
    node *next = current->next;
    node *tmp;
    current->next = NULL;
    while (next) {
        tmp = next->next;
        next->next = current;
        current = next;
        next = tmp;
    }
    head = current;
}

void recursiveReverse(node *&head) {
    if (!head || !(head->next)) {
        return;
    }
    node *current = head->next;
    recursiveReverse(current);
    head->next->next = head;
    head->next = NULL;
    head = current;
    return;
}



int main() {
    int num,index;
    vi v;
    node *head1 = NULL,*head2 = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        pushHead(head1,rand()%20);
    }
    print(head1);
    recursiveReverse(head1);
    print(head1);
    /*while (cin >> num) {
        deleteNode(head1,num);
        print(head1);
    }*/
}

