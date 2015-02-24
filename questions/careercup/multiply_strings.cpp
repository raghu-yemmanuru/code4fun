#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int c2n(char ch) {
    return ch-'0';
}

char n2c(int n) {
    return n+'0';
}

string add(string a, string b) {
    if (a.size() > b.size()) {
        swap(a,b);
    }

    int carry = 0;
    int sum;
    string c;
    int i = a.size()-1, j = b.size()-1;
    while (i >= 0 && j >= 0) {
        sum = c2n(a[i]) + c2n(b[j]) + carry;
        carry = sum/10;
        c.push_back(n2c(sum%10));
        i--;
        j--;
    }
    while(j >= 0) {
        sum = c2n(b[j]) + carry;
        carry = sum/10;
        c.push_back(n2c(sum%10));
        j--;
    }
    if(carry) {
        c.push_back(n2c(carry));
    }
    reverse(c.begin(),c.end());
    return c;
}

string multiply_digit(string a, int d) {
    int carry = 0;
    int sum;
    string c;
    for (int i = a.size()-1; i >= 0; i--) {
        sum = c2n(a[i])*d + carry;
        carry = sum/10;
        c.push_back(n2c(sum%10));
    }
    if (carry) {
        c.push_back(n2c(carry));
    }
    reverse(c.begin(),c.end());
    return c;
}

string multiply_strings1(string a, string b) {
    if (a.size() > b.size()) {
        swap(a,b);
    }
    string c = "0";
    string temp;
    for (int i = a.size()-1; i >= 0; i--) {
        int digit = c2n(a[i]);
        int carry = 0;
        int sum;
        temp.clear();
        for (int j = b.size()-1; j >= 0; j--) {
            sum = c2n(b[j])*digit + carry;
            carry = sum/10;
            temp.push_back(n2c(sum%10));
        }
        if (carry) {
            temp.push_back(n2c(carry));
        }
        reverse(temp.begin(),temp.end());
        for (int k = 0; k < a.size()-1-i; i++) {
            temp.push_back('0');
        }
        c = add(c,temp);
    }

    return c;
}

string multiply_strings(string a, string b) {
    if (a.size() > b.size()) {
        swap(a,b);
    }
    string temp;
    string sum = "0";
    for (int i = a.size()-1; i >= 0; i--) {
        temp = multiply_digit(b,c2n(a[i]));
        for (int k = 0; k < a.size()-1-i; k++) {
            temp.push_back('0');
        }
        sum = add(sum,temp);
    }
    return sum;
}

int main() {
    string a,b;
    cin >> a >> b;
    cout << multiply_strings(a,b) << endl;
}
