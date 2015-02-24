#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;
typedef vector<int> vi;

int random_number() {
    return rand()%5;
}

void printConsecutive(const vi &v, int sum) {
    int curSum = 0;
    for (int beg=0,end=0; end < v.size(); end++) {
        curSum += v[end];
        while (curSum > sum) {
            curSum -= v[beg];
            beg++;
        }
        if (curSum == sum) {
            copy(v.begin()+beg,v.begin()+end+1,ostream_iterator<int>(cout," "));
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

    int num;
    while (cin >> num) {
        printConsecutive(v,num);
    }
}
