#include <iostream>
#include <vector>

using namespace std;

class DisjointSets {
private:
    int V;
    vector<int> ranks;
    vector<int> parents;
public:
    DisjointSets(int _v):V(_v) {
        ranks.assign(V,0);
        parents.assign(V,-1);
    }
    void makeset(int);
    int find(int);
    void unite(int,int);
};

void DisjointSets::makeset(int element) {
    if (parents[element] != -1) {
        cout << element << " Already part of a set " << parents[element] << endl;
        return;
    }
    parents[element] = element;
    ranks[element] = 1;
}

int DisjointSets::find(int element) {
    vector<int> path;
    while (parents[element] != element) {
        path.push_back(element);
        element = parents[element];
    }

    for (int i = 0; i < path.size(); i++) {
        parents[path[i]] = element;
    }

    return element;
}

void DisjointSets::unite(int a, int b) {
    int s1 = find(a);
    int s2 = find(b);

    if (s1 == s2) {
        return;
    }
    if(ranks[s1] < ranks[s2]) {
        parents[s1] = s2;
        ranks[s2] += ranks[s1];
    } else {
        parents[s2] = s1;
        ranks[s1] += ranks[s2];
    }
}

/*int main() {
    int elements = 10;
    DisjointSets ds(elements);
    for (int i = 0; i < elements; i++) {
        ds.makeset(i);
    }
    ds.unite(0,5);
    ds.unite(5,3);
    ds.unite(7,9);

    cout << ds.find(0) << endl;
    cout << ds.find(3) << endl;
    cout << ds.find(5) << endl;
    cout << ds.find(7) << endl;
    cout << ds.find(9) << endl;
}*/
