#include <iostream>
#include <string>
using namespace std;

void permute(string s,string result) {
    if (result.size() == s.size()) {
        cout << result << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        permute(s,result+s[i]);
    }
}

int main() {
    string s;
    cin >> s;
    permute(s,"");
}
