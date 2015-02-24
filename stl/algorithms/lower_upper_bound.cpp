#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int myints[] = {10,20,30,30,20,10,10,20};
    vector <int> v(myints,myints+8);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator low,up;
    low = lower_bound(v.begin(),v.end(),40);

    if (low != v.end()) {
        cout << "low points to " << *low << endl;
    }

    cout << "low distance is " << (low-v.begin()) << endl;

    up = upper_bound(v.begin(),v.end(),40);
    if (up != v.end()) {
        cout << "up points to " << *up << endl;
    }

    cout << "up distance is " << (up-v.begin()) << endl;
}
