#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void printSequence(int num) {
    string s = "1";
    stringstream ss;
    int j = 0;
    char ch;
    int count = 0;
    for (int i = 1; i <= num; i++) {
        j = 0;
        ss.clear();
        ss.str("");
        while(j < s.size()) {
            ch = s[j];
            count = 0;
            while(j < s.size() && s[j] == ch) {
                j++;
                count++;
            }
            ss << count << ch;
        }
        s = ss.str();
        cout << s << endl;
    }
    //cout << s << endl;
}

int main() {
    int num;
    cin >> num;
    printSequence(num);
    return 0;
}
