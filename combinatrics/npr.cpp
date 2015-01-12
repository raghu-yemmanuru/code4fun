#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;
int total = 0;

void npr(set<char> in, vector<char> &out, int pos, int r) {

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
        set<char> temp(in.begin(),itr);
        temp.insert(++itr,in.end());
        npr(temp,out,pos+1,r);
    }
}

int main() {
    set<char> in;
    char value;
    int r;
    cout << "Usage : <r> <keys>" << endl;

    cin >> r;
    while (cin >> value) {
        in.insert(value);
    }
    vector<char> out(r);

    copy(in.begin(),in.end(),ostream_iterator<char>(cout, " "));
    cout << endl;
    npr(in,out,0,r);
    cout << total << " " << endl;
}
