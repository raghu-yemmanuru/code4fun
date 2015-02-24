#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseWords(string &line) {
    if (line.size() == 0) {
        return;
    }

    int i = 0, j = 0;
    while (j < line.size()) {
        while(j < line.size() && line[j] != ' ') {
            j++;
        }
        reverse(line.begin()+i,line.begin()+j);
        while(j < line.size() && line[j] == ' ') {
            j++;
        }
        i = j;
    }
    reverse(line.begin(),line.end());
}

int main() {
    string line;
    getline(cin,line);
    reverseWords(line);
    cout << line << endl;
}
