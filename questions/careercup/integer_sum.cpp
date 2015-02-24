#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> vi;

void partition(int num,vi &v, int max) {
    if (num == 0) {
        copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }

    for (int i = num; i >= 1; i--) {
        if (i > max) {
            continue;
        }
        v.push_back(i);
        partition(num-i,v,i);
        v.pop_back();
    }
}
        
    
int main() {
    int num;
    cin >> num;
    vi v;
    partition(num,v,num);
}
