#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;


typedef vector<int> vi;
typedef vector<vi > vvi;

int LCS(string &a, string &b) {
    int m = a.size();
    int n = b.size();
    vvi L(m+1,vi(n+1,0));
    int maxVal = -1, maxIndex = -1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                L[i][j] = 1 + L[i-1][j-1];
            }
            if (maxVal < L[i][j]) {
                maxVal = L[i][j];
                maxIndex = i;
            }
        }
    }

    if (maxVal > 0) {
        int j = maxIndex;
        int i = j - maxVal + 1;
        copy(a.begin()+i,a.begin()+j+1,ostream_iterator<char>(cout," "));
        cout << endl;
    }

    return maxVal;
}

int main() {
    string a,b;
    cin >> a >> b;
    cout << "Longest Common Substring is " << LCS(a,b) << endl;
    return 0;
}
