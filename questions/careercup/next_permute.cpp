#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool next_permute(string &s) {
    int j = s.size() - 1;
    while (j > 0 && s[j-1] >= s[j]) {
        j--;
    }
    int i = j-1;
    if (i < 0) {
        return false;
    }
    int k = s.size() - 1;
    while (k > i && s[k] <= s[i]) {
        k--;
    }
    swap(s[i],s[k]);
    reverse(s.begin()+j,s.end());
    return true;
}

int main() {
    string s;
    cin >> s;
    while (next_permute(s)) {
        cout << s << endl;
    }
}
