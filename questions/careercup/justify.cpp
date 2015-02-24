#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<string> vs;

string justify(string s) {
    stringstream ss(s);
    stringstream result;
    string word;
    vs words;
    int len = 0;

    while(ss >> word) {
        words.push_back(word);
        len += word.size();
    }

    int delimSize = 0;
    int delimRemainder = 0;
    if(words.size() == 1) {
        delimSize = (s.size()-len);
    } else {
        delimSize = (s.size()-len)/(words.size()-1);
        delimRemainder = (s.size()-len)%(words.size()-1);
    }
    /*copy(words.begin(),words.end(),ostream_iterator<string>(cout,"\n"));
    cout << endl;
    cout << s.size() << " " << len << endl;
    cout << delimSize << " " << delimRemainder << endl;*/
    for (int i = 0; i < words.size(); i++) {
        result << words[i];
        if (i < words.size()-1) {
            for (int i = 0; i < delimSize; i++) {
                result << " ";
            }
            if (delimRemainder) {
                result << " ";
                delimRemainder--;
            }
        }
    }

    return result.str();
}

int main() {
    string s1,s2;
    getline(cin,s1);
    s2 = justify(s1);
    cout << s2 << endl;
}
