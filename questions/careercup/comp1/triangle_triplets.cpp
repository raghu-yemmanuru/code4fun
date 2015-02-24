#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

bool isValid(const vi &v) {
    if (v.size() != 3) {
        return false;
    }
    return (v[0]+v[1] > v[2] && v[1]+v[2] > v[0] && v[0]+v[2] > v[1]);
}

void printTriangles(const vi &v, int index, vi result) {
    if (result.size() == 3 && isValid(result)) {
        copy(result.begin(),result.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }
    for (int i = index; i < v.size(); i++) {
        result.push_back(v[i]);
        printTriangles(v,i+1,result);
        result.pop_back();
    }
}

int main() {
    vi v; 
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    vi r;
    printTriangles(v,0,r);
}
