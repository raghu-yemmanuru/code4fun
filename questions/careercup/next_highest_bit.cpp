#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int setBit(int &num, int i) {
    num |= (1 << i);
}

int clearBit(int &num, int i) {
    num &= ~(1 << i);
}

int getBit(int &num, int i) {
    if ((num & (1 << i))) {
        return 1;
    }
    return 0;
}

void printBinary(int num) {
    string s;
    while(num) {
        if (num&1) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
        num >>= 1;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
}
        
int next_highest(int num) {
    int i = 0;
    while (getBit(num,i) == 0) {
        i++;
    }
    int count = 0;
    while(getBit(num,i) == 1) {
        count++;
        i++;
    }
    //cout << "i is " << i << endl;
    //printBinary(num);
    setBit(num,i);
    //printBinary(num);
    for (int j = 0; j < i; j++) {
        clearBit(num,j);
    }
    //printBinary(num);
    count--;
    for (int j = 0; j < count; j++) {
        setBit(num,j);
    }
    //printBinary(num);
    return num;
}

int next_lowest(int num) {
    int i = 0;
    while(getBit(num,i) == 1) {
        i++;
    }
    int count = 0;
    while(getBit(num,i) == 0) {
        count++;
        i++;
    }
    clearBit(num,i);
    for (int j = 0; j < i; j++) {
        setBit(num,j);
    }
    count--;
    for (int j = 0; j < count; j++) {
        clearBit(num,j);
    }
    return num;
}

int main() {
    int num;
    cin >> num;
    printBinary(num);
    printBinary(next_highest(num));
    printBinary(next_lowest(num));
    //printBinary(next_highest(num));
}
