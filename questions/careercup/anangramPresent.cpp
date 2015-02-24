#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef map<char,int> Map;

bool isAnagramPresent(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();
    if (m > n) {
        return false;
    }

    Map m1,m2;
    int count = 0;
    for (int i = 0; i < m; i++) {
        m1[s1[i]]++;
    }

    int i = 0;
    for (; i < m; i++) {
        if (m1[s2[i]] > 0 && m2[s2[i]] < m1[s2[i]]) {
            count++;
        }
        m2[s2[i]]++;
    }

    if (count == m) {
        return true;
    }

    for (; i < n; i++) {
        m2[s2[i-m]]--;
        if (m2[s2[i-m]] < m1[s2[i-m]]) {
            count--;
        }
        if (m1[s2[i]] > 0 && m2[s2[i]] < m1[s2[i]]) {
            count++;
        }
        if (count == m) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    if (isAnagramPresent(s1,s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}
