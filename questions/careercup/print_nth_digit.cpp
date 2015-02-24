#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    
    int count = 0, r = -1;
    while (count < n) {
        r++;
        count += (pow(10,r)*9*(r+1));
    }
    r--;
    int prev_digits = 0,prev_numbers = 0;
    for (int i = 0; i <= r; i++) {
        prev_digits += (pow(10,r)*9*(r+1));
        prev_numbers += (pow(10,r)*9);
    }
    
    int cur_region_size = (r+2);
    int cur_number, cur_offset;
    
    int remaining_digits = n - prev_digits;
    int remaining_numbers = (remaining_digits-1)/(r+2);
    cur_number = prev_numbers + remaining_numbers + 1;
    cur_offset = (remaining_digits-1)%(r+2);
    
    stringstream ss;
    cout << "current number " << cur_number << endl;
    ss << cur_number;
    string val = ss.str();
    //reverse(val.begin(),val.end());
    cout << val[cur_offset] << endl;
}
        
