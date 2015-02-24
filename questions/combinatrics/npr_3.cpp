#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;
int total = 0;

void npr(multiset<char> in, vector<char> &out, int pos) {
    if (pos == out.size()) {
        total++;
        copy(out.begin(),out.end(),ostream_iterator<char>(cout," "));
        cout << endl;
        return;
    }

    if (!in.size()) {
        return;
    }

    for(multiset<char>::iterator itr = in.begin(); itr != in.end(); ) {
        if (out[pos] == *itr) {
            ++itr;
            continue;
        }

        out[pos] = *itr;
        multiset <char> dummy(in.begin(),itr);//in.lower_bound(*itr));
        dummy.insert(++itr, in.end());
        npr(dummy, out, pos+1);
    }
}

int main() {
    int n,r;
    char item;
    cin >> r;

    vector<char> output(r);
    multiset <char> input;

    while(cin >> item) {
        input.insert(item);
    }
    npr(input,output, 0);
    cout << total << endl;
}
