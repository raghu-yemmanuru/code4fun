#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool permute(string &num) {
    int i = num.size()-1;
    while(i > 0 && num[i-1] >= num[i]) {
        i--;
    }
    int j = i-1;
    if (j < 0) {
        return false;
    }
    int k = num.size()-1;
    while (num[k] <= num[j]) {
        k--;
    }
    if (k <= j) {
        return false;
    }
    swap(num[k],num[j]);
    string::iterator itr;
    reverse(num.begin()+i,num.end());

    return true;
}

int main() {
    string num;
    cin >> num;
    int total = 0;
    cout << ++total << " " << num << endl;
    while (permute(num)) {
        cout << ++total << " " << num << endl;
    }
}

