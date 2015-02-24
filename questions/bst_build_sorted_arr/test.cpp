#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

void print_in_order (Node *root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    cout << root->val << " ";
    print_in_order(root->right);

    return;
}

Node *buildTree (int arr[], int start, int end) {
    if (end < start) {
        return NULL;
    }

    Node *toReturn = new Node;
    if (start == end) {
        toReturn->val = arr[start];
        toReturn->left = toReturn->right = NULL;
        return toReturn;
    }

    int middle = (start + end)/2;
    toReturn->val = arr[middle];
    toReturn->left = buildTree(arr, start, middle-1);
    toReturn->right = buildTree(arr, middle+1, end);

    return toReturn;
}
    
int main () {
    int *arr = NULL;
    Node *root = NULL;
    srand(time(NULL));
    try {
        arr = new int[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = rand()%100;
        }
        sort (arr, arr + 10);
        root = buildTree(arr, 0, 9);
    } catch (bad_alloc &ex) {
        cerr << "Exception in program " << endl;
        return 0;
    }

    print_in_order(root);
    cout << endl;
    delete[] arr;
    return 0;
}

