#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
int total = 0;

//Generate partitions of value n without having values more than max in the set
void partition(int n, int max, int pos, vector<int> &v) {
    if (n == 0) {
        cout << ++total << ": ";
        copy(v.begin(),v.begin()+pos,ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }

    for (int i = max; i > 0; i--) {
        v[pos] = i;
        //Force the order to always non-increasing
        partition(n-i,min(n-i,i),pos+1,v);
    }
}
        
int main() {
    int n;
    cin >> n;
    vector<int> v(n,0);
    partition(n,n,0,v);
}
