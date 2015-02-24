#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef map<char,bool> Map;
typedef map<char,int> Map1;

int longest1(const string &s) {
    Map1 m;
    int beg = 0, end = 0;
    if (s.size() == 0) {
        return 0;
    }

    int maxLen = 0, maxEnding = 0;
    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) == m.end() || i-m[s[i]] > maxEnding) {
            maxEnding++;
        } else {
            maxEnding = i-m[s[i]];
        }
        maxLen = max(maxEnding,maxLen);
        m[s[i]] = i;
    }
    return maxLen;

}

int longest(const string &s) {
    if (s.size() == 0) {
        return 0;
    }
    int end = 0,beg = 0;
    Map m;
    m[s[end++]] = true;
    int cur_len = 1, max_len = 1;
    while(end < s.size()) {
        if (!m[s[end]]) {
            m[s[end++]] = true;
            cur_len++;
        } else {
            while(s[beg] != s[end]) {
                m[s[beg++]] = false;
            }
            beg++;
            cur_len = end-beg+1;
            end++;
        }
        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }
    return max_len;
}

int main() {
    string s;
    cin >> s;
    cout << "Longest string without repeated character " << longest(s) << endl;
    cout << "Longest string without repeated character " << longest1(s) << endl;
}
