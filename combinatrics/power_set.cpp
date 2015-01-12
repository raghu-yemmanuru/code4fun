#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;
int total = 0;

void power_multiset(multiset<char> in, vector<char> &out, int pos) {
    total++;
    cout << "{";
    copy(out.begin(),out.begin()+pos,ostream_iterator<char>(cout,","));
    cout << "}" << endl;

    if (!in.size()) {
        return;
    }

    for (multiset<char>::iterator itr = in.begin(); itr != in.end();) {
        out[pos] = *itr;
        power_multiset(multiset<char>(++itr,in.end()),out,pos+1);
    }
}

int main() {
    multiset<char> in;
    vector<char> out;
    char value;

    while (cin >> value) {
        in.insert(value);
    }
    out.reserve(in.size());

    copy(in.begin(),in.end(),ostream_iterator<char>(cout, " "));
    cout << endl;
    power_multiset(in,out,0);
    cout << total << " " << endl;
}
