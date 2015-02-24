#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<pair<int,int> > vp;

int main() {
    vs words;
    vi c;
    string word;
    int L;


    words.push_back("");
    c.push_back(0);
    cin >> L;
    while(cin >> word) {
        words.push_back(word);
        c.push_back(word.size());
    }

    int n = words.size()-1;

    vvi S(n+1,vi(n+1,0));

    for (int i = 1; i <= n; i++) {
        S[i][i] = L-c[i];
        for (int j = i+1; j <= n; j++) {
            S[i][j] = S[i][j-1] - 1 - c[j];
        }
    }

    vi T(n+1,L*L);
    vi B(n+1,0);
    T[0] = 0;


    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= j; i++) {
            if (S[i][j] >= 0 && T[j] > T[i-1] + S[i][j]*S[i][j]) {
                T[j] = T[i-1] + S[i][j]*S[i][j];
                B[j] = i;
            }
        }
    }

    vp path;
    int k = n;
    while (k > 0) {
        path.push_back(make_pair(B[k],k));
        cout << "Pushing " << k << " " << B[k] << endl;
        k = B[k]-1;
    }
    reverse(path.begin(),path.end());

    for (int i = 0; i < path.size(); i++) {
        int start = path[i].first;
        int end = path[i].second;
        for (int j = start; j < end; j++) {
            cout << words[j] << " ";
        }
        cout << words[end] << endl;
    }
}
