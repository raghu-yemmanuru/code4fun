#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void npr(vector <char> &in, vector<char> &out, int i) {
    if (i == out.size()) {
        copy(out.begin(),out.end(),ostream_iterator<char>(cout," "));
        cout << endl;
        return;
    }

    for (int l = 0; l < in.size(); l++) {
        vector<char>::iterator itr = find(out.begin(), out.begin()+i, in[l]);
        if (itr == out.begin() + i) {
            out[i] = in[l];
            npr(in,out,i+1);
        }
    }
}

int main() {
    int n,r;
    cin >> r;

    vector <char> v;
    copy(istream_iterator<char>(cin),istream_iterator<char>(),back_inserter(v));
    n = v.size();

    vector <char> out(r);

    npr(v,out,0);
}
