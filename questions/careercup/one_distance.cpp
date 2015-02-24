#include <iostream>
#include <string>

using namespace std;

bool oneEdit(string a, string b) {
    if (a.size() > b.size()) {
        swap(a,b);
    }
    if (b.size() - a.size() > 1) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return (a.substr(i+1) == b.substr(i+1) || a.substr(i) == b.substr(i+1) || a.substr(i) == b.substr(i+1));
        }
    }
    return true;
}

int main() {
    string a,b;
    cin >> a >> b;
    if (oneEdit(a,b)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
