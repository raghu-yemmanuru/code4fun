#include <iostream>
#include <string>

using namespace std;

void remove_a_bc(string &s) {
    int i = 0;
    for (int j = 0; j < s.size();) {
        if (s[j] == 'b') {
            j++;
            continue;
        } else if (j < s.size()-1 && s[j] == 'a' && s[j+1] == 'c') {
            j+= 2;
            continue;
        }
        s[i++] = s[j++];
    }
    cout << "i " << i << endl;
    //s[i] = '\0';
    s.erase(s.begin()+i,s.end());
    return;
}


int main() {
    string s;
    getline(cin,s);
    remove_a_bc(s);
    cout << "new string " << s << endl;
}
