#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
struct node {
    int row;
    int col;
    int val;
    node(int _row, int _col, int _val): row(_row),
                                        col(_col),
                                        val(_val)
    {}
};
typedef struct node Node;

struct nodeCompare {
    bool operator()(Node &lhs, Node &rhs) {
        return rhs.val < lhs.val;
    }
};
typedef struct nodeCompare NodeCompare;

//Build Mean Heap

int kthsmallest(int arr[4][4], int n, int k) {
    if (k < 0 || k > n*n) {
        return INT_MAX;
    }

    NodeCompare mycompare;
    vector<Node> v1;
    for (int i = 0; i < n; i++) {
        v1.push_back(Node(0,i,arr[0][i]));
    }
    make_heap(v1.begin(),v1.end(),mycompare);

    for (int i = 0; i < k-1; i++) {
        pop_heap(v1.begin(),v1.end(),mycompare);

        // Now the min element is at the back
        Node val = v1.back();
        v1.pop_back();

        int newVal = val.row < n-1 ? arr[val.row+1][val.col] : INT_MAX;
        v1.push_back(Node(val.row+1,val.col,newVal));

        //Push the new element added at the back into heap
        push_heap(v1.begin(),v1.end(),mycompare);
    }

    //Again pull the min element to the back
    pop_heap(v1.begin(),v1.end(),mycompare);
    return v1.back().val;
}

int main() {
    int a[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
    cout << "3rd smallest number is " << kthsmallest(a,4,3) << endl;
    return 0;
}
