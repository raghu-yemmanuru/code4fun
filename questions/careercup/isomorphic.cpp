#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char,char> Map;
bool isoMorphic(string a, string b) {
    if (a.size() != b.size()) {
        return false;
    }

    if (a.size() == b.size() && a.size() == 0) {
        return true;
    }

    Map m1,m2;

    for (int i = 0; i < a.size(); i++) {
        if (m1.find(a[i]) != m1.end() && m1[a[i]] != b[i]) {
            return false;
        }
        if (m2.find(b[i]) != m2.end() && m2[b[i]] != a[i]) {
            return false;
        }
        m1[a[i]] = b[i];
        m2[b[i]] = a[i];
    }

    return true;
}
    
int main() {
    string a,b;
    cin >> a >> b;
    Map m;
    if (isoMorphic(a,b)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
