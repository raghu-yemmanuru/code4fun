#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int,int> MapI;
int rand_number() {
    return rand()%50;
}

void threeSum(vi &v, MapI &m, int num) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            if (m.find(num-v[i]-v[j]) != m.end()) {
                cout << i << " " << j << " " << m[num-v[i]-v[j]] << endl;
                cout << v[i] << " " << v[j] << " " << num-v[i]-v[j] << endl;
                return;
            }
        }
    }
}

void threeSum1(vi v, int num) {
    sort(v.begin(),v.end());
    int a,b,c;
    int low,high,sum;
    for (int i = 0; i < v.size(); i++) {
        a = v[i];
        low = i+1;
        high = v.size()-1;
        while(low <= high) {
            b = v[low];
            c = v[high];
            sum = a+b+c;
            if (sum == num) {
                cout << i << " " << low << " " << high << endl;
                cout << v[i] << " " << v[low] << " " << v[high] << endl;
                return;
            } else if (sum > num) {
                high--;
            } else {
                low++;
            }
        }
    }
}


int main() {
    srand(time(NULL));
    vi v(20);
    MapI m;
    generate(v.begin(),v.end(),rand_number);
    for (int i = 0; i < v.size(); i++) {
        m[v[i]] = i;
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    int num;
    while (cin >> num) {
        //threeSum(v,m,num);
        threeSum1(v,num);
    }
}

