#include <iostream>

using namespace std;

string isNumber(string &s) {
    int i = 0;
    int dots = 0;
    bool negative;

    if (s[0] == '-') {
        negative = true;
        i++;
    }

    if (s.size() == 0 || s[i] == '.' || s[s.size()-1] == '.') { 
        return "False";
    }

        
    for (;i < s.size(); i++) {
        if(s[i] == '.') {
            dots++;
            if (dots > 1) {
                return "False";
            }
        } else if (s[i]-'0' < 0 || s[i]-'0' > 9) {
                return "False";
        }
    }

    return "True";
}

int main() {
    string s;
    int dots = 0;
    if (dots++ > 0) {
        cout << "WEIRD" << endl;
    }
    cin >> s;
    cout << "Answer is " << isNumber(s) << endl;
}
