#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

inline int c2n(char ch) {
    return ch-'0';
}
inline char n2c(int num) {
    return num + '0';
}

string add(string a, string b) {
    int carry = 0;
    int i, j;
    int val;
    string c;
    if (a.size() > b.size()) {
        swap(a,b);
    }
    i = a.size()-1, j = b.size()-1;
    while (i >= 0 && j >= 0) {
        val = c2n(a[i]) + c2n(b[j]) + carry;
        carry = val/10;
        c.push_back(n2c(val%10));
        i--;
        j--;
    }
    while (j >= 0) {
        val = c2n(b[j]) + carry;
        carry = val/10;
        c.push_back(n2c(val%10));
        j--;
    }
    if (carry) {
        c.push_back(n2c(carry));
    }
    reverse(c.begin(),c.end());
    return c;
}

string multiply_digit(string a,int d) {
    int carry = 0;
    int val;
    string c;
    for (int i = a.size()-1; i >= 0; i--) {
        val = c2n(a[i])*d + carry;
        c.push_back(n2c(val%10));
        carry = val/10;
    }
    if (carry) {
        c.push_back(n2c(carry));
    }
    reverse(c.begin(),c.end());
    return c;
}

string multiply(string a,string b) {
    if (a.size() == 0 || b.size() == 0) {
        return "0";
    }
    if (a.size() < b.size()) {
        swap(a,b);
    }
    string sum = "0";
    string tmp;
    int k;
    for (int i = b.size()-1; i >= 0; i--) {
        tmp = multiply_digit(a,c2n(b[i]));
        k = b.size()-1-i;
        while(k--) {
            tmp.push_back('0');
        }
        sum = add(sum,tmp);
    }
    return sum;
}
        
int main() {
    string a,b;
    cin >> a >> b;
    cout << add(a,b) << endl;
    cout << multiply_digit(a,9) << endl;
    cout << multiply(a,b) << endl;
}
