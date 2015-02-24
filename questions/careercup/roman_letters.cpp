#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef map<int,string> Map;

void buildMap(Map &m) {
    m[1] = "I";
    m[2] = "II";
    m[3] = "III";
    m[4] = "IV";
    m[5] = "V";
    m[6] = "VI";
    m[7] = "VII";
    m[8] = "VIII";
    m[9] = "IX";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
    return;
}

string roman(int num, Map &m) {
    string result = "";
    while(num) {
        if (num >= 1000) {
            result += m[1000];
            num -= 1000;
        } else if (num >= 900) {
            result += m[100];
            result += m[1000];
            num -= 900;
        } else if (num >= 500) {
            result += m[500];
            num -= 500;
        } else if (num >= 400) {
            result += m[100];
            result += m[500];
            num -= 400;
        } else if (num >= 100) {
            result += m[100];
            num -= 100;
        } else if (num >= 90) {
            result += m[10];
            result += m[100];
            num -= 90;
        } else if (num >= 50) {
            result += m[50];
            num -= 50;
        } else if (num >= 40) {
            result += m[10];
            result += m[50];
            num -= 40;
        } else if (num >= 10) {
            result += m[10];
            num -= 10;
        } else {
            result += m[num];
            num -= num;
        }
    }
    return result;
}

int main() {
    int num;
    Map m;
    buildMap(m);
    while(cin >> num) {
        cout << "Roman Version: " << roman(num,m) << endl;
    }
}
