#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node *getNode(int val) {
    Node *ptr = new Node;
    ptr->data = val;
    return ptr;
}

Node *buildBst() {
    Node *root = getNode(35);

    root->left = getNode(27); 
    root->right = getNode(50); 

    root->left->left = getNode(25);
    root->left->right = getNode(30);
    root->right->left = getNode(40);
    root->right->right = getNode(65);

    root->left->left->left = getNode(20);
    root->left->left->left->right = getNode(23);
    root->left->left->left->right->left = getNode(22);
    root->left->left->left->right->right = getNode(24);

    root->right->right->left = getNode(60);
    root->right->right->left->right = getNode(64);

    return root;
}

void print_in_order(Node *root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    cout << root->data << endl;
    print_in_order(root->right);
}

void buildNextStack(Node *root, deque<Node *> &s) {
    while (root) {
        s.push_back(root);
        root = root->left;
    }
    return;
}

void printStack(deque<Node *> &s) {
    deque<Node *>::reverse_iterator itr;
    for (itr = s.rbegin(); itr != s.rend(); itr++) {
        cout << (*itr)->data << endl;
    }
    return;
}

void buildPrevStack(Node *root, deque<Node *> &s) {
    while (root) {
        s.push_back(root);
        root = root->right;
    }
    return;
}

Node *getPrev(deque<Node *> &pStack) {
    Node *toReturn = pStack.back();
    pStack.pop_back();

    Node *pLeft = toReturn->left;
    while (pLeft) {
        pStack.push_back(pLeft);
        pLeft = pLeft->right;
    }
    return toReturn;
}

Node *getNext(deque<Node *> &nStack) {
    Node *toReturn = nStack.back();
    nStack.pop_back();

    Node *pRight = toReturn->right;
    while (pRight) {
        nStack.push_back(pRight);
        pRight = pRight->left;
    }
    return toReturn;
}

bool findSum(Node *root, deque<Node *> &nStack, deque<Node *> &pStack, int sum) {
    Node *leftSide = getNext(nStack);
    Node *rightSide = getPrev(pStack);

    while (true) {
        if (leftSide == rightSide || leftSide == NULL) {
            break;
        }

        cout << "Left " << leftSide->data << " Right " << rightSide->data << endl;
        int cur_sum = leftSide->data + rightSide->data;
        if (cur_sum == sum) {
            return true;
        }

        if (cur_sum < sum) {
            leftSide = getNext(nStack);
        }
    
        if (cur_sum > sum) {
            rightSide = getPrev(pStack);
        }
    }

    return false;
}

int main() {
    Node *root = buildBst();
    deque<Node *> nextStack;
    deque<Node *> prevStack;

    buildNextStack(root, nextStack);
    buildPrevStack(root, prevStack);
    //printStack(nextStack);
    bool ret = findSum(root, nextStack, prevStack, 46);
    //cout << "returned value " << ret << endl;
    //print_in_order(root);
}
    
