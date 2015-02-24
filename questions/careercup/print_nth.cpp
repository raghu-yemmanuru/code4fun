#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int numers_per_region(int r) {
    return pow(10,r)*9;
}

int digits_per_region(int r) {
    return numers_per_region(r)*(r+1);
}

int region_for_digit(int digit) {
    int count = 0;
    int r = 0;
    while(count < digit) {
        count += digits_per_region(r++);
    }
    r--;
    return r;
}

int printDigit(int n) {
    int r = region_for_digit(n);
    int prev_digits = 0;
    for (int i = 0; i < r; i++) {
        prev_digits += digits_per_region(i);
    }

    int prev_numbers = 0;
    for (int i = 0; i < r; i++) {
        prev_numbers += numers_per_region(i);
    }

    int remaining_digits = n - prev_digits;
    int remaining_numbers = (remaining_digits-1)/(r+1);

    int cur_number = prev_numbers + remaining_numbers + 1;
    int cur_offset = (remaining_digits-1)%(r+1);

    stringstream ss;
    ss << cur_number;
    string s = ss.str();
    return s[cur_offset]-'0';
}

int main() {
    int n;
    while(cin >> n) {
        cout << "Digit is " << printDigit(n) << endl;
    }
}
