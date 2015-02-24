#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
void reverseWords(string &s) {
    reverse(s.begin(),s.end());
    int i = 0, j;
    while (i < s.size()) {
        j = i;
        while (j < s.size() && s[j] != ' ') {
            j++;
        }
        reverse(s.begin()+i,s.begin()+j);
        while(j < s.size() && s[j] == ' ') {
            j++;
        }
        i = j;
    }
    return;
}
        
int main() {
    string s;
    getline(cin,s);
    reverseWords(s);
    cout << s << endl;
}
