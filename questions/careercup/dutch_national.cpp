#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
using namespace std;

void dnf2(vector<int> &v) {
    int k = 0;
    int i = 0;
    int j = v.size()-1;

    while (k <= j) {
        if (v[k] < 1) {
            swap(v[k],v[i]);
            i++;
            k++;
        } else if (v[k] > 1) {
            swap(v[k],v[j]);
            j--;
        } else {
            k++;
        }
    }
    return;
}

void dnf1(vector<int> &v) {
    int k = 0;
    int i = -1, j = v.size();
    while(i < j && k < v.size()) {
        if (v[k] == 1) {
            k++;
        } else if(v[k] == 0) {
            if (k > i) {
                swap(v[k],v[i+1]);
                i++;
            } else {
                k++;
            }
        } else {
            if (k < j) {
                swap(v[k],v[j-1]);
                j--;
            } else {
                k++;
            }
        }
    }
    return;

}

int main() {
    int num;
    vector<int> v;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        v.push_back(rand()%3);
    }

    int i = -1, j = v.size();
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    dnf2(v);

    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    return 0;
}
