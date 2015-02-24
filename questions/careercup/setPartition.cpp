#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vi;
int random_number() {
    return rand()%30;
}

int minSum;
void minSubSet(vi S, int total, int sum, vi &minSet, vi result) {
    if (abs(total - 2*sum) < minSum) {
        minSum = abs(total - 2*sum);
        minSet = result;
    }
    for (int i = 0; i < S.size(); i++) {
        result.push_back(S[i]);
        minSubSet(vi(S.begin()+i+1,S.end()),total,sum+S[i],minSet,result);
        result.pop_back();
    }
}

int main() {
    vi v(10); 
    srand(time(NULL));
    generate(v.begin(),v.end(),random_number);
    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    vi r;
    minSum = numeric_limits<int>::max();
    minSubSet(v,sum,0,r,vi());

    int target = 0;
    for (int i = 0; i < r.size(); i++) {
        target += r[i];
    }
    copy(r.begin(),r.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    cout << sum << " " << target << endl;
}
