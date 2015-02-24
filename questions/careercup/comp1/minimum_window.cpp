#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;
typedef map<char,int> Map;

string minWindow(const string &s, const string &t) {
    Map S,T;
    int m = t.size();

    int beg = 0, end = 0, count = 0;
    int minLen = numeric_limits<int>::max();
    string toReturn;
    for (int i = 0; i < t.size(); i++) {
        T[t[i]]++;
    }
    for (beg = 0, end = 0; end < s.size(); end++) {
        if (T[s[end]] == 0) {
            continue;
        }
        if (S[s[end]] < T[s[end]]) {
            count++;
        }
        S[s[end]]++;
        if (count == m) {
            while (T[s[beg]] == 0 || S[s[beg]] > T[s[beg]]) {
                if (S[s[beg]] > T[s[beg]]) {
                    S[s[beg]]--;
                }
                beg++;
            }
            if (minLen > (end-beg+1)) {
                minLen = (end-beg+1);
                toReturn = s.substr(beg,end-beg+1);
                cout << toReturn << endl;
            }
        }
    }
    return toReturn;
}

int main() {
    string s,t;
    cin >> s >> t;
    cout << "Minimum window string " << minWindow(s,t) << endl;
}
