#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int random_number() {
    return rand()%5;
}

void printConsecutive(const vi &v, int sum) {
    int cur_sum = 0;
    int beg = 0, end = 0;
    for (beg = 0, end = 0; end < v.size(); end++) {
        cur_sum += v[end];
        while(beg < end && cur_sum > sum) {
            cur_sum -= v[beg];
            beg++;
        }
        if (cur_sum == sum) {
            copy(v.begin()+beg, v.begin()+end+1,ostream_iterator<int>(cout," "));
            cout << endl;
        }
    }
}

int main() {
    vi v(10);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_number);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    int sum;
    while(cin >> sum) {
        printConsecutive(v,sum);
    }
}
