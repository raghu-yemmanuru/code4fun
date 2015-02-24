#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iterator>

using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<pair<int,int> > vp;

int main() {
    string s;
    vs w;
    vi c;
    int L;
    cin >> L;
    w.push_back("");
    c.push_back(0);
    while (cin >> s) {
        w.push_back(s);
        c.push_back(s.size());
    }

    int n = w.size()-1;

    vvi S(n+1,vi(n+1,0));
    for (int i = 1; i <= n; i++) {
        S[i][i] = L - c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            S[i][j] = S[i][j-1] - c[j] - 1;
        }
    }

    vi T(n+1,L*L);
    vi B(n+1,0);
    T[0] = 0;
    B[0] = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= j; i++) {
            if (S[i][j] >= 0) {
                if (T[j] >= T[i-1] + S[i][j]*S[i][j]) {
                    T[j] = T[i-1] + S[i][j]*S[i][j];
                    B[j] = i;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //cout << S[i][j] << "\t";
        }
        //cout << endl;
    }

    //cout << "T " << endl;
    /*copy(T.begin(),T.end(),ostream_iterator<int>(cout," "));
    cout << endl;*/

    /*cout << "B " << endl;
    copy(B.begin(),B.end(),ostream_iterator<int>(cout," "));
    cout << endl;*/

    vp path;
    for (int i = n; i > 0;) {
        path.push_back(make_pair(B[i],i));
        i = B[i]-1;
    }

    for(vp::reverse_iterator itr = path.rbegin(); itr != path.rend(); itr++) {
        int i = itr->first;
        int j = itr->second;
        for (int k = i; k < j; k++) {
            cout << w[k] << " ";
        }
        cout << w[j];
        cout << endl;
    }
}

