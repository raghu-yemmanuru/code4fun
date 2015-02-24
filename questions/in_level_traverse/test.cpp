#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node *buildTree (vector <int> inVec, vector <int> levelVec) {
    if (inVec.size() != levelVec.size()) {
        cout << "Error in building Tree" << endl;
        exit(1);
    }

    /*cout << "In Vector ==> ";
    for (int i = 0; i < inVec.size(); i++) {
        cout << inVec[i] << " ";
    }
    cout << endl;

    cout << "Level Vector ==> ";
    for (int i = 0; i < levelVec.size(); i++) {
        cout << levelVec[i] << " ";
    }
    cout << endl;*/


    if (!(inVec.size() && levelVec.size())) {
        return NULL;
    }
    int rootData = levelVec[0];

    vector<int>::iterator inVecItr = find (inVec.begin(), inVec.end(), rootData);

    vector<int> leftInVec (inVec.begin(), inVecItr);
    vector <int> rightInVec (inVecItr+1, inVec.end());
    vector <int> leftLevelVec;
    vector <int> rightLevelVec;

    leftLevelVec.reserve(leftInVec.size());
    rightLevelVec.reserve(rightInVec.size());

    for (int i = 1; i < levelVec.size(); i++) {
        vector<int>::iterator itr = find(leftInVec.begin(), leftInVec.end(), levelVec[i]);
        if (itr != leftInVec.end()) {
            leftLevelVec.push_back(levelVec[i]);
            continue;
        }

        itr = find(rightInVec.begin(), rightInVec.end(), levelVec[i]);
        if (itr != rightInVec.end()) {
            rightLevelVec.push_back(levelVec[i]);
            continue;
        }
    }

    Node *rootNode = new Node;
    rootNode->val = rootData;
    rootNode->left = buildTree(leftInVec, leftLevelVec);
    rootNode->right = buildTree(rightInVec, rightLevelVec);

    return rootNode;
}

void print_in_order (Node *root)
{
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    cout << root->val << " , ";
    print_in_order(root->right);
    
    return;
}

int main () {
    int in[] = {4,8,10,12,14,20,22};
    int level[] = {20,8,22,4,12,10,14};

    vector<int> inVec (in, in + (sizeof(in)/sizeof(int)));
    vector<int> levelVec (level, level + (sizeof(level)/sizeof(int)));

    Node * root = NULL;
    try {
        root = buildTree (inVec, levelVec);
    } catch (...) {
        cout << "Exception Occured" << endl;
    }

    cout << "Printing in order traversal" << endl;
    print_in_order(root);
    cout << endl;
    return 0;
}
