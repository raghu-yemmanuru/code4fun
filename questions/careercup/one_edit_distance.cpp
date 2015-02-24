#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool zeroDistance(string a, string b) {
    if (a.size() == 0 && b.size() == 0) {
        return true;
    } else if (a.size() == 0 || b.size() == 0) {
        return false;
    } else {
        return (a == b);
    }
}

bool oneDistance(string a, string b) {
    if (abs(int(a.size()-b.size())) >= 2) {
        return false;
    }

    for (int i =0,j=0; i < a.size() && j < b.size(); i++,j++) {
        if (a[i] != b[j]) {
            if (!(zeroDistance(a.substr(i+1),b.substr(j+1)) ||
                zeroDistance(a.substr(i),b.substr(j+1)) || 
                zeroDistance(a.substr(i+1),b.substr(j)))) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string a,b;
    cin >> a >> b;
    if (oneDistance(a,b)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
