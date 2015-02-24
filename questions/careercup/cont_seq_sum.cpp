#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vi;

int random_number() {
    return rand()%7;
}

void printAllSequences(const vi &v, int val) {
    vi sum(v.size()+1,0);
    sum[1] = v[0];
    for (int i = 2; i <= v.size(); i++) {
        sum[i] = v[i-1]+sum[i-1];
    }

    for (int i = 1; i <= v.size(); i++) {
        for (int j = 1; j <= i; j++) {
            if (sum[i]-sum[j-1] == val) {
                //cout << j-1 << " " << i-1 << endl;
                copy(v.begin()+j-1,v.begin()+i,ostream_iterator<int>(cout," "));
                cout << endl;
            }
        }
    }
}

int main() {
   vi v(10);
   srand(time(NULL));
   generate(v.begin(),v.end(),random_number);
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
   cout << endl;
   int val;
   while(cin >> val) {
     printAllSequences(v,val);
   }
}
