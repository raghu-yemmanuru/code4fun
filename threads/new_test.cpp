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

void mergeSort(vi *p_v) {
    vi &v = *p_v;
    int left = 0, right = v.size()-1;
    cout << left << " " << right << endl;
    if (v.size() <= 10) {
        sort(v.begin(),v.end());
        copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }

    int mid = left + (right-left)/2;
    vi leftHalf(v.begin()+left,v.begin()+mid+1);
    vi rightHalf(v.begin()+mid+1,v.end());
    thread t1(mergeSort,&leftHalf);
    thread t2(mergeSort,&rightHalf);
    t1.join();
    t2.join();
    //mergeSort(leftHalf);
    //mergeSort(rightHalf);

    cout << "After merge Sort " << endl;
    copy(leftHalf.begin(),leftHalf.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    copy(rightHalf.begin(),rightHalf.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < leftHalf.size() && j < rightHalf.size()) {
        if (leftHalf[i] < rightHalf[j]) {
            v[count++] = leftHalf[i++];
        } else  {
            v[count++] = rightHalf[j++];
        }
    }
    while(i < leftHalf.size()) {
        v[count++] = leftHalf[i++];
    }
    while(j < rightHalf.size()) {
        v[count++] = rightHalf[j++];
    }
    return;
}

int main() {
    vi v(20);
    srand(time(NULL));
    generate(v.begin(),v.end(),random_num);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    mergeSort(&v);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
