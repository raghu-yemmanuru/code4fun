#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef map<int,int> Map;

struct node {
    int val;
    node *left,*right;
    node(int _val):val(_val),left(NULL),right(NULL) {}
};

void buildMap(int *in, int n, Map &m) {
    for (int i = 0; i < n; i++) {
        m[in[i]] = i;
        //cout << in[i] << " " << m[in[i]] << endl;
    }
    return;
}

node *build(int *in, int *pre, int n, int offset, Map &m) {
    if (n == 0) {
        return NULL;
    }

    int root_val = pre[0];
    node *root = new node(root_val);
    //cout << root_val << endl;

    int i = m[root_val] - offset;
    root->left = build(in,pre+1,i,offset,m);
    root->right = build(in+i+1,pre+1+i,n-i-1,offset+i+1,m);

    return root;
}

node *build2(int *in, int *pre, int low, int high, Map &m) {
    if (low > high) {
        return NULL;
    }
    int i = m[pre[0]];
    int n = i-low+1;
    node *root = new node(pre[0]);
    root->left = build2(in,pre+1,low,i-1,m);
    root->right = build2(in+n,pre+n,low+n,high,m);
    return root;
}

node* build1(int *in, int *pre, int low, int high, Map &m) {
    if (low > high) {
        return NULL;
    }
    int idx = m[pre[0]];
    int i = idx-low;
    node *root = new node(pre[0]);
    root->left = build1(in,pre+1,low,idx-1,m);
    root->right = build1(in+i+1,pre+i+1,idx+1,high,m);
    return root;
}

void printIn(node *root) {
    if (!root) {
        return;
    }
    printIn(root->left);
    cout << root->val << " ";
    printIn(root->right);
}

int main() {
    int n;
    n = 8;
    int in[8] = {4,10,3,1,7,11,8,2};
    int pre[8] = {7,10,4,3,1,2,8,11};
    /*int num;
    cin >> n;
    in = new int[n];
    pre = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        pre[i] = num;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        in[i] = num;
    }*/
    Map m;
    buildMap(in,n,m);
    node *root1 = build(in,pre,n,0,m);
    node *root2 = build1(in,pre,0,n-1,m);
    node *root3 = build2(in,pre,0,n-1,m);
    printIn(root1);
    cout << endl;
    printIn(root2);
    cout << endl;
    printIn(root3);
    cout << endl;
}
