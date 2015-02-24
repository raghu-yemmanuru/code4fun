#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isEven(char ch) {
    if((ch-'0')&1) {
        return false;
    }
    return true;
}

bool next_even_number(string &s) {
    int i,j,k,l;
    j = s.size()-1;
    int evens = 0;
    //cout << "Size is " << s.size() << endl;
    while (j > 0 && s[j] <= s[j-1]) {
        j--;
    }
    i = j-1;
    if (i < 0 ) {
        return false;
    }
    for (l = i; l < s.size(); l++) {
        if (isEven(s[l])) {
            evens++;
        }
    }

    k = s.size()-1;
    while(s[k] <= s[i]) {
        k--;
    }

    if (evens == 1 && isEven(s[k]) || evens == 0) {
        while(i >= 0 && !isEven(s[i])) {
            i--;
        }
        if (i < 0) {
            return false;
        }
    }

    k = s.size()-1;
    while(k >= i && s[k] <= s[i]) {
        k--;
    }
    if (k < i) {
        return false;
    }
    swap(s[k],s[i]);
    
    int maxEvenIndex = -1;
    for (j = i+1; j < s.size(); j++) {
        if (isEven(s[j])) {
            if (maxEvenIndex == -1 || s[maxEvenIndex] < s[j]) {
                maxEvenIndex = j;
            }
        }
    }
    if (maxEvenIndex < 0) {
        return false;
    }
    swap (s[maxEvenIndex],s[s.size()-1]);
    sort(s.begin()+i+1,s.end()-1);
    cout << "Here " << s << endl;
    return true;
}

int main() {
    string s;
    cin >> s;
    while(next_even_number(s)) {
        cout << s << endl;
    }
}
