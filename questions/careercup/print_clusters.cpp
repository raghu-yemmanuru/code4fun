#include <iostream>
#include <vector>

using namespace std;
struct node {
    int data;
    node *prev,*next;
    node(int _data):data(_data),prev(NULL),next(NULL){}
};
typedef vector<int> vi;

void printClusters(node *head, vi &v) {
    node *current = head;
    int i = 0;
    while (current &&  i < v.size()) {
        if (current->data == v[i]) {
            cout << "( ";
            while(current && i < v.size() && current->data == v[i]) {
                cout << current->data << " ";
                current = current->next;
                i++;
            }
            cout << ")\t";
        } else {
            current = current->next;
        }
    }
    cout << endl;
}

int main() {
    int num,val;
    cin >> num;
    node dummy(-1);
    node *current = &dummy;
    for (int i = 0; i < num; i++) {
        cin >> val;
        current->next = new node(val);
        current = current->next;
    }
    node *head = dummy.next;

    vi v;
    while(cin >> val) {
        v.push_back(val);
    }

    printClusters(head,v);
}
