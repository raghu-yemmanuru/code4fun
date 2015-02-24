#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> vi;

void printContLargest(const vi &v) {
    int beg = 0, end = 0;
    int max = -1;
    int i = 0, j = 0;
    if (v.size() == 0) {
        return;
    }

    while (j < v.size()) {
        while (j < v.size()-1 && v[j] < v[j+1]) {
            j++;
        }
        if (max < (j-i+1)) {
            beg = i;
            end = j;
            max = j-i+1;
        }
        j++;
        i = j;
    }

    cout << "Max length is " << max << " between " << beg << " " << end << endl;
    copy(v.begin()+beg,v.begin()+end+1,ostream_iterator<int>(cout," "));
    cout << endl;
}

int main() {
    int num;
    vi v;
    while(cin >> num) {
        v.push_back(num);
    }
    printContLargest(v);
}
