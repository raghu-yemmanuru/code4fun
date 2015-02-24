#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int total = 0;
void permute(vector<char> &v, int i) {
    if (i == v.size()) {
        cout << ++total << ")\t";
        copy (v.begin(),v.end(),ostream_iterator<char>(cout, " "));
        cout << endl;
        return;
    }
    for (int l = i; l < v.size(); l++) {
        swap(v[i],v[l]);
        permute(v,i+1);
        swap(v[i],v[l]);
    }
}

int main() {
    vector<char> v;
    copy(istream_iterator<char>(cin),istream_iterator<char>(),back_inserter(v));
    permute(v,0);
}
