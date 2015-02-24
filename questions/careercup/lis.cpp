#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> vi;

void printLis(const vi &v) {
    if (v.size() == 0) {
        return;
    }

    vi L(v.size(),1);
    vi P(v.size(),-1);
    int max_index = -1, max_count = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = i-1; j >= 0; j--) {
            if (v[j] < v[i] && L[i] < L[j]+1) {
                L[i] = L[j]+1;
                P[i] = j;
            }
        }
        if (max_count < L[i]) {
            max_count = L[i];
            max_index = i;
        }
    }

    vi path;
    cout << "Max LIS is " << max_count << " ending at " << max_index << endl;
    while(max_index >= 0) {
        path.push_back(v[max_index]);
        max_index = P[max_index];
    }

    copy(path.rbegin(),path.rend(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main() {
    int num;
    vi v;
    while (cin >> num) {
        v.push_back(num);
    }
    printLis(v);
}
        
