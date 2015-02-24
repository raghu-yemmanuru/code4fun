#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
typedef map<string,int> Map;

string nonRepeat(const string &s) {
    stringstream ss(s);
    string word;
    Map m;
    while(ss >> word) {
        m[word]++;
    }
    ss.clear();
    ss.str();
    ss.str(s);
    while(ss >> word) {
        if (m[word] == 1) {
            return word;
        }
    }

    return "NONE";
}

int main() {
    string s;
    getline(cin,s);
    cout << "First non repeating word " << nonRepeat(s) << endl;
}
