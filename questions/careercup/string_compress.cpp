#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i = -1, j = 0;
    int n = s.size();
    int count;
    while (j < n) {
        count = 1;
        char ch = s[j];
        while (s[j] == s[j+1] && j < n-1) {
            count++;
            j++;
        }
        j++;
        s[++i] = ch;
        
        if(count > 1) {
            stringstream ss;
            ss << count;
            string temp = ss.str();
            ss.str("");
            for (int k = 0; k < temp.size(); k++) {
                s[++i] = temp[k];
            }
        }
    }
    if (i > 0 && i < n) {
        s.erase(i+1,n-i-1);
    }
    cout << s << endl;
} 
        
