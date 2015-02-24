#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb > vvb;

bool found(vs &keyboard, int i, int j, string word, int match, vvb &visited) {
    if (match == word.size()) {
        return true;
    }
    if (i < 0 || i >= keyboard.size() || j < 0 || j >= keyboard[i].size() || visited[i][j]) {
        return false;
    }
    if (keyboard[i][j] != word[match]) {
        return false;
    }

    visited[i][j] = true;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (found(keyboard,i+x,j+y,word,match+1,visited)) {
                visited[i][j] = false;
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;
}

bool canForm(vs &keyboard, string word) {
    vvb visited(4,vb(4,false));
    for (int i = 0; i < keyboard.size(); i++) {
        for (int j = 0; j < keyboard.size(); j++) {
            if (found(keyboard,i,j,word,0,visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vs keyboard;
    string s;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        keyboard.push_back(s);
    }

    while (cin >> s) {
        if (canForm(keyboard,s)) {
            cout << "Word can be formed" << endl;
        } else {
            cout << "Word can't be formed" << endl;
        }
    }
}
