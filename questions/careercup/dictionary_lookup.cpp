#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(string s,string result,int r)  {
    if (result.size() == r) {
        cout << result << endl;
        return;
    }
    if (s.size() == 0) {
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            continue;
        }
        permute(s.substr(0,i) + s.substr(i+1),result + s[i],r);
    }
}

int main() {
    string s;
    int r;
    cin >> s;
    cin >> r;
    sort(s.begin(),s.end());
    //permute(s,"",r);
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(),s.end()));
}
