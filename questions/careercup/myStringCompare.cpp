#include <iostream>
#include <string>
using namespace std;

int myCompare(const string &s1, const string &s2) {
    for (int i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
    }
    if (s1.size() == s2.size()) {
        return 0;
    } else if (s1.size() < s2.size()) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    cout << "MyCompare " << myCompare(s1,s2) << endl;
}
