#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
typedef vector<string> vs;
typedef vector<vs > vvs;
typedef vector<int> vi;

void permute(vvs &v, vi &r, int pos) {
    if (pos == r.size()) {
        for (int i = 0; i < r.size(); i++) {
            cout << v[i][r[i]] << "  ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < v[pos].size(); i++) {
        r[pos] = i;
        permute(v,r,pos+1);
    }
}

int main() {
    vvs v;
    vi p;
    string s;
    int n;
    int i = 0;
    while(getline(cin,s)) {
        v.push_back(vs());
        stringstream ss(s);
        string tmp;
        while(ss >> tmp) {
            v[i].push_back(tmp);
        }
        i++;
    }
    vi r(v.size(),0);
    permute(v,r,0);
}
