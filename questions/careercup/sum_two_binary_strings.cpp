#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
typedef string::reverse_iterator SRItr;

string add(string &a,string &b) {
    int i,j,k,sum;
    k = 0;
    stringstream result;

    SRItr itr1 = a.rbegin();
    SRItr itr2 = b.rbegin();

    for (;itr1 != a.rend() && itr2 != b.rend(); itr1++,itr2++) {
        i = (*itr1)-'0';
        j = (*itr2)-'0';
        sum = i+j+k;
        result << (sum&1);
        k = (sum >> 1);
    }

    for (;itr2 != b.rend(); itr2++) {
        i = (*itr2)-'0';
        sum = i+k;
        result << (sum&1);
        k = (sum >> 1);
    }
    if (k) {
        result << k;
    }

    string s = result.str();
    reverse(s.begin(),s.end());
    //cout << s << endl;
    return s;
}

int main() {
    string a,b;
    cin >> a >> b;
    if (a.size() > b.size()) {
        swap(a,b);
    }

    cout << add(a,b) << endl;
}

