#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};

void printAllPaths(node *root, int level, int target, vi v) {
    if (!root) {
        return;
    }
    v.push_back(root->data);
    int sum = 0;
    for (int i = v.size()-1; i >= 0; i--) {
        sum += v[i];
        if (sum == target) {
            copy(v.begin()+i,v.end(),ostream_iterator<int>(cout," "));
            cout << endl;
        }
    }
    printAllPaths(root->left,level+1,target,v);
    printAllPaths(root->right,level+1,target,v);
    v.pop_back();
        
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(-1);
    root->right = new node(3);
    root->right->left = new node(-2);
    root->right->right = new node(4);

    int sum;
    vi v;
    while(cin >> sum) {
        printAllPaths(root,0,sum,v);
    }
}
    
