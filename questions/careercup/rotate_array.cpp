#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void rotate(vector<int> &v, int r) {
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+r);
    reverse(v.begin()+r,v.end());
}

int main() {
    int num;
    vector<int> v;
    int r;
    cin >> r;
    while(cin >> num) {
        v.push_back(num);
    }
    r = r%(v.size());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    rotate(v,r);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
