#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node *left,*right;
    node(int _d):data(_d),left(NULL),right(NULL){}
};

typedef pair<node*,node*> Pair;
node *nullPtr= NULL;

void KthSmallest(node *root, int &count, int &result) {
    if (!root || count < 0) {
        return;
    }

    KthSmallest(root->left,count,result);
    if (count == 0) {
        result = root->data;
    }
    count--;
    KthSmallest(root->right,count,result);
}

int main() {
    node *root = new node(8);
    root->left = new node(4);
    root->left->left = new node(3);
    root->left->left->left = new node(2);
    root->left->right = new node(5);
    root->right = new node(11);
    root->right->left = new node(9);
    root->right->right = new node(12);

    int k,result,count;
    while(cin >> k) {
        result = -1;
        count = 0;
        KthSmallest(root,k,result);
        cout << result << endl;
    }
}
