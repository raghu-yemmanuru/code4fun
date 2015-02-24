#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string looksay(const string &s) {
    stringstream result;
    char ch;
    int i = 0;
    int count = 0;
    while(i < s.size()) {
        ch = s[i];
        count = 1;
        i++;
        while(i < s.size() && s[i] == ch) {
            count++;
            i++;
        }
        result << count << ch;
    }
    return result.str();
}

int main() {
    string s = "1";
    for (int i = 0; i < 5; i++) {
        s = looksay(s);
        cout << s << endl;
    }
}
