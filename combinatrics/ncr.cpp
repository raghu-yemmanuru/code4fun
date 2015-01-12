#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;
int total = 0;

void ncr(set<char> in, vector<char> &out, int pos, int r) {

    if (pos == r) {
        total++;
        copy(out.begin(),out.begin()+pos,ostream_iterator<char>(cout," "));
        cout << endl;
        return;
    }

    if (!in.size()) {
        return;
    }

    for (set<char>::iterator itr = in.begin(); itr != in.end();) {
        out[pos] = *itr;
        ncr(set<char>(++itr,in.end()),out,pos+1,r);
    }
}

int main() {
    set<char> in;
    vector<char> out;
    char value;
    int r;

    cin >> r;
    while (cin >> value) {
        in.insert(value);
    }
    out.reserve(r);

    copy(in.begin(),in.end(),ostream_iterator<char>(cout, " "));
    cout << endl;
    ncr(in,out,0,r);
    cout << total << " " << endl;
}
