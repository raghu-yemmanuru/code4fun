#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<string> vs;

vs generate(string s) {
    vs toReturn;
    if (s.size() == 0) {
        return toReturn;
    }

int main() {
    string s;
    vs v = generate(s);
    copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
    cout << endl;
}
