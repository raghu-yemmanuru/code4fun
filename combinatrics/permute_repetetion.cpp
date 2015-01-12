#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
int total = 0;

void permute(vector<char> &in, vector<char> &out, int pos) {
    if (pos == out.size()) {
        ++total;
        copy (out.begin(), out.end(), ostream_iterator<char>(cout, " "));
        cout << endl;
        return;
    }
    for (int i = 0; i < in.size(); i++) {
        out[pos] = in[i];
        permute(in,out,pos+1);
    }
}


int main() {
    vector<char> in,out;
    copy(istream_iterator<char>(cin),istream_iterator<char>(),back_inserter(in));
    out.resize(in.size());
    permute(in,out,0);
    cout << total << endl;
}
