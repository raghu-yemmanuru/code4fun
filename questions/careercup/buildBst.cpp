#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vi;

struct node {
    int data;
    node *left,*right;
    node(int _d):data(_d),left(NULL),right(NULL){}
};

int random_number() {
    return rand()%100;
}

node *buildBST(const vi &v, int low, int high) {
    if (low > high) {
        return NULL;
    }
    int mid = low + (high-low)/2;
    node *root = new node(v[mid]);
    root->left = buildBST(v,low,mid-1);
    root->right = buildBST(v,mid+1,high);
    
    return root;
}

void printInOrder(node *root) {
    if (!root) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    vi v(10);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_number);
    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    
    node *root = buildBST(v,0,v.size()-1);
    printInOrder(root);
    cout << endl;
}

    
