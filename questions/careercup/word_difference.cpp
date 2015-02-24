#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int wordDistance(string &line, string &w1, string &w2) {
    stringstream ss(line);
    string word;
    int i = 0,j = 0;
    int count = 0;
    while (ss >> word) {
        ++count;
        if (word == w1 && !i) {
            i = count;
        }
        if (word == w2 && !j) {
            j = count;
        }
    }

    return j-i;

}

int main() {
    string line;
    getline(cin,line);
    string word1,word2;

    cin >> word1 >> word2;
    cout << "Distance is " << wordDistance(line,word1,word2);
}
