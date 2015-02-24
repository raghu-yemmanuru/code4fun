#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int _val):val(_val),left(NULL),right(NULL){}
};
typedef pair<node*,int> Pair;
void closest_util(node *root, int num, Pair &p) {
    if (!root) {
        return;
    }
    if (p.second > abs(root->val - num)) {
        p.second = abs(root->val - num);
        p.first = root;
    }
    if (num < root->val) {
        closest_util(root->left,num,p);
    } else if(num > root->val) {
        closest_util(root->right,num,p);
    }
    return;
}
    
int closest(node *root, int val) {
    Pair p = make_pair(root,numeric_limits<int>::max());
    closest_util(root,val,p);
    if (p.first) {
        return p.first->val;
    }
    cout << "No such nodes present" << endl;
    return -1;
}

int main() {
    node *root = new node(2);
    root->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(8);
    
    cout << "Closest Key to 5 is " << closest(root,5) << endl;
}
