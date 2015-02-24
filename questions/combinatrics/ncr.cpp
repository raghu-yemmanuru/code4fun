#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void ncr(vector<char> &in, vector<char> &out, int index, int pos) {
    if (pos == out.size()) {
        copy(out.begin(),out.end(),ostream_iterator<char>(cout, " "));
        cout << endl;
        return;
    }

    for (int i = index; i < in.size(); i++) {
        out[pos] = in[i];
        ncr(in,out,i+1,pos+1);
    }
}

int main() {
    int n, r;
    cin >> r;
    vector <char> in, out(r);
    copy (istream_iterator<char>(cin), istream_iterator<char>(),back_inserter(in));
    ncr(in,out,0,0);
}
