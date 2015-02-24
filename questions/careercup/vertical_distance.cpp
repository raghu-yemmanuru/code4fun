#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> vi;
typedef map<int,vi > Map;

struct node {
    int data;
    node *left,*right;
    node(int _data):data(_data),left(NULL),right(NULL){}
};

void traverse(node *root, int hd, Map &m) {
    if (!root) {
        return;
    }
    m[hd].push_back(root->data);
    traverse(root->left,hd-1,m);
    traverse(root->right,hd+1,m);
}

void printVertical(node *root) {
    Map m;
    traverse(root,0,m);
    for(Map::iterator itr = m.begin(); itr != m.end(); itr++) {
        copy(itr->second.begin(),itr->second.end(),ostream_iterator<int>(cout," "));
        cout << endl;
    }
}

void findMinMax(node *root, int &Min, int &Max, int hd) {
    if (!root) {
        return;
    }

    Min = min(hd,Min);
    Max = max(hd,Max);
    findMinMax(root->left,Min,Max,hd-1);
    findMinMax(root->right,Min,Max,hd+1);
}

void printLine(node *root, int line, int hd) {
    if (!root) {
        return;
    }
    if (line == hd) {
        cout << root->data << " ";
    }
    printLine(root->left,line,hd-1);
    printLine(root->right,line,hd+1);
}

void printVertical1(node *root) {
    int min = 0, max = 0;
    if (!root) {
        return;
    }
    findMinMax(root,min,max,0);
    for(int i = min; i <= max; i++) {
        printLine(root,i,0);
        cout << endl;
    }
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    printVertical1(root);
}
