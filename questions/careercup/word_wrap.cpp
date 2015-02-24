#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<pair<int,int> > vp;

int main() {
    string word;
    vs words;
    vi c;
    int L;


    c.push_back(0);
    words.push_back("");

    cin >> L;

    while (cin >> word) {
        words.push_back(word);
        c.push_back(word.size());
    }
    vvi S(c.size(),vi(c.size(),0));

    int n = c.size()-1;

    for (int i = 1; i <= n; i++) {
        S[i][i] = L-c[i];
        for (int j = i+1; j <= n; j++) {
            S[i][j] = S[i][j-1] - 1 - c[j];
        }
    }

    vi T(c.size(),L*L);
    vi B(c.size(),0);

    T[0] = 0;

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= j; i++) {
            if (S[i][j] >= 0 && T[j] >= T[i-1] + (S[i][j]*S[i][j])) {
                T[j] = T[i-1] + (S[i][j]*S[i][j]);
                B[j] = i;
            }
        }
    }

    int j = n;
    vp v;
    while (j > 0) {
        v.push_back(make_pair(B[j],j));
        j = B[j]-1;
    }

    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++) {
        int start = v[i].first;
        int end = v[i].second;
        for (int k = start; k < end; k++) {
            cout << words[k]  << " ";
        }
        cout << words[end] << endl;
    }
}

