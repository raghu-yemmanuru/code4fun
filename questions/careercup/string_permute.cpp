#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<char> vc;

void permute(string s, string result) {
    if (result.size()) {
        cout << result << endl;
    }

    if (s.size() == 0) {
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            continue;
        }
        permute(s.substr(0,i)+s.substr(i+1),result+s[i]);
    }

}

int main() {
    string s;
    cin >> s;
    vc v;
    permute(s,"");
}
