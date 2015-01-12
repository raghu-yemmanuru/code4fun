#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>


// Input can contain repeated keys like "a a b b c d e"

using namespace std;
int total = 0;

void permute(multiset<char> in, vector<char> &out, int pos, int r) {

    if (pos == r) {
        total++;
        copy(out.begin(),out.begin() + pos,ostream_iterator<char>(cout," "));
        cout << endl;
        return;
    }

    if (!in.size()) {
        return;
    }

    for (multiset<char>::iterator itr = in.begin(); itr != in.end();) {
        if (out[pos] == *itr) {
            ++itr;
            continue;
        }

        out[pos] = *itr;
        multiset<char> temp(in.begin(),itr);
        temp.insert(++itr,in.end());
        permute(temp,out,pos+1,r);
    }
}

int main() {
    multiset<char> in;
    char value;
    int r;

    cin >> r;

    while (cin >> value) {
        in.insert(value);
    }
    vector<char> out(in.size());

    permute(in,out,0,r);
    cout << total << " " << endl;
}
