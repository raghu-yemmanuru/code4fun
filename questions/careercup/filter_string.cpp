#include <iostream>
#include <string>
using namespace std;

void remove(string &s, const string &f) {
    int cur = -1;
    for (int runner = 0; runner < s.size(); runner++) {
        if (f.find(s[runner]) == string::npos) {
            s[++cur] = s[runner];
        }
    }
    s.erase(s.begin()+cur+1,s.end());
    return;
}
int main() {
    string s,f;
    cin >> s >> f;
    remove(s,f);
    cout << s << endl;
}
