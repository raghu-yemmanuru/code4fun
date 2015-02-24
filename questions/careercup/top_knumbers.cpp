#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
using namespace std;

void top_k(vector<int> v, int rank) {
    int k = rank;
    int low = 0, high = v.size()-1;
    int pivot;
    while (low <= high) {
        pivot = v[high];
        int i = low - 1;
        for (int j = low; j <= high-1; j++) {
            if (v[j] <= pivot) {
                swap(v[i+1],v[j]);
                i++;
            }
        }
        swap(v[i+1],v[high]);

        int count = (i+1)-(low) + 1;
        if (k == count) {
            break;
        } else if (k < count) {
            high = i;
        } else {
            low = i+2;
            k = k - count;
        }
    }
    for (int i = 0; i < rank; i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}
        
int main() {
    vector<int> v,sv;
    int k,idx,n;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        int num = rand()%30;
        v.push_back(num);
        sv.push_back(num);
    }
    sort(sv.begin(),sv.end());
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    copy(sv.begin(),sv.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    while(cin >> k) {
        top_k(v,k);
    }
    return 0;
}
