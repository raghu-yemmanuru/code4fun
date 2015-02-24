#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int val;
    node *next;
    node(int _val):val(_val),next(NULL) {}
};

int main () {
    srand(time(NULL));
    int num;
    node *root = NULL;
    node *current;
    for (int i = 0; i < 20; i++) {
        num = rand()%10;
        if (!root) {
            root = new node(num);
            current = root;
        } else {
            current->next = new node(num);
            current = current->next;
        }
    }

    current = root;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    cin >> num;
    node dummy(-1);
    dummy.next = root;
    node *prev = &dummy;
    current = root;
    while (current) {
        if (current->val == num) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = prev->next;
            current = current->next;
        }
    }

    current = root;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

}

        
        
