#include <iostream>
#include <string>

using namespace std;


bool one_distance(string &a, string &b) {
    if (a.size() > b.size()) {
        swap(a,b);
    }
    if (b.size() - a.size() > 1) {
        return false;
    }
    
    int diffCount = 0;
    int sameLength = 0;
    if (a.size() == b.size()) {
        sameLength = 1;
    }
    
    int i = 0,j = 0;
    
    for (; i < a.size() && j < b.size(); i++,j++) {
        if (a[i] != b[j]) {
            diffCount++;
            if (sameLength) {
                i++; j++;
            } else {
                j++;
            }
        }
    }

    if ( j != b.size()) {
        diffCount++;
    }
    
    cout << "Diff count is " << diffCount << endl;
    return (diffCount == 1);
}

int main() {
    string a,b;
    cin >> a >> b;
    if (one_distance(a,b)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
