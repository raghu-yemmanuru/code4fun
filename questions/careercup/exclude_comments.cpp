#include <iostream>
#include <string>

using namespace std;

enum state_t {COMMENT=0,UNCOMMENT};

int main () {
    string s;
    state_t q = UNCOMMENT;
    while (getline(cin,s)) {
        for (int i = 0; i < s.size();) {
            switch(q) {
                case UNCOMMENT:
                    if (i < s.size()-1 && s[i] == '/' && s[i+1] == '*') {
                        q = COMMENT;
                        i += 2;
                    } else {
                        cout << s[i++];
                    }
                    break;
                case COMMENT:
                    if (i < s.size()-1 && s[i] == '*' && s[i+1] == '/') {
                        q = UNCOMMENT;
                        i += 2;
                    } else {
                        i++;
                    }
                    break;
            }
        }
        cout << endl;
    }
}
