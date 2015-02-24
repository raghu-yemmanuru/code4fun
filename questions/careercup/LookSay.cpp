#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string Look(int num) {
    stringstream ss;
    ss << num;
    string s = ss.str();
    ss.str("");
    string result = "";
    int i = 0,count = 0;
    while (i < s.size()) {
        count = 1;
        char c = s[i];
        while (i < s.size()-1 && c == s[i+1]) {
            count++;
            i++;
        }
        i++;
        ss << count << c;
    }
    result = ss.str();
    ss.str("");
    return result;
}

int Say(string s) {
    int i = 0,count= 0;
    char c;
    int result;
    stringstream ss;
    for (int i = 0; i < s.size(); i+=2) {
        count = s[i]-'0';
        c = s[i+1];
        for (int j = 0; j < count; j++) {
            ss << c;
        }
    }
    ss >> result;
    return result;
}

int main() {
    int num;
    string s;
    cin >> num;
    cout << Look(num) << endl;
    cin >> s;
    cout << Say(s) << endl;
}
