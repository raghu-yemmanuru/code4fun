#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
string lookandsay (int num) {
    stringstream ss("1");
    for (int i = 0; i < num; i++) {
        string sofar = ss.str();
        ss.str("");
        int j = 0;
        char ch = sofar[j];
        int count = 1;
        for (int j = 1; j < sofar.size(); j++) {
            if (sofar[j] == sofar[j-1]) {
                count++;
            } else {
                ss << count << ch;
                count = 1;
                ch = sofar[j];
            }
        }
        ss << count << ch;
    }
    return ss.str();
}
                
int main() {
    int num;
    cin >> num;
    cout << lookandsay(num) << endl;
}
