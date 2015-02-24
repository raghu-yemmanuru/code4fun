#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vi;

void print_message(string msg1, string msg2) {
    cout << "Hello" << msg1 << " " << msg2 << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }
}

int random_num() {
    return rand()%100;
}

void mergeSort(vi *p_v, int left, int right) {

    vi &v = *p_v;
    cout << left << " " << right << endl;
    if (left > right) {
        return;
    }
    if ((right-left+1) <= 10) {
        sort(v.begin()+left,v.begin()+right+1);
        /*copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
        cout << endl;*/
        return;
    }

    int mid = left + (right-left)/2;
    thread t1(mergeSort,p_v,left,mid);
    thread t2(mergeSort,p_v,mid+1,right);
    t1.join();
    t2.join();

    cout << "Before Merge " << endl;
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    int i = left;
    int j = mid+1;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            i++;
        } else {
            int tmp = v[j];
            for (int k = j; k > i; k--) {
                v[k] = v[k-1];
            }
            v[i] = tmp;
            i++;j++;//mid++;
        }
    }
    return;
}

int main() {
    vi v(20);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_num);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    mergeSort(&v,0,v.size()-1);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
