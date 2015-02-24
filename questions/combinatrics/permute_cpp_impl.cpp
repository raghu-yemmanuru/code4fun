#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int total = 0;
    vector<char> in;
    copy(istream_iterator<char>(cin),istream_iterator<char>(), back_inserter(in));

    sort(in.begin(),in.end());
    do {
        total++;
        copy(in.begin(),in.end(),ostream_iterator<char>(cout," "));
        cout << endl;
    } while (next_permutation(in.begin(),in.end()));
    cout << total << endl;
}

