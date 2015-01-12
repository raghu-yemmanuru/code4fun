#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;
int total = 0;

void permute(vector<char> &in, int pos) {
    if (pos == in.size()) {
        ++total;
        copy(in.begin(),in.end(),ostream_iterator<char>(cout, " "));
        cout << endl;
        return;
    }

    for (int i = pos; i < in.size(); i++) {
        swap(in[i],in[pos]);
        permute(in,pos+1);
        swap(in[i],in[pos]);
    }
}

int main() {
    vector<char> in;
    copy(istream_iterator<char>(cin),istream_iterator<char>(),back_inserter(in));
    permute(in,0);
    cout << total << endl;
}
