// Longest Continuous Non repeating character sequence from a string
//
#include <iostream>
#include <string>

using namespace std;

int main () {
    string str("aabcdefdghiajk");
    //string str("abcdebd");
    int found[255];
    int maxSequence = -1;
    int start = 0;
    int end = 0;
    int maxEnd = -1;
    int maxStart = -1;

    for (int i = 0; i < 255; i++) {
        found[i] = 0;
    }

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!found[ch]) {
            found[ch] = 1;
            end++;
        } else {
            /*if (str[start] == ch) {
                start++;
            } else {*/
            while (str[start] != ch) {
                found[str[start++]] = 0;
            }
            start++;
            //}
            end++;
        }

        if ((end - start) > maxSequence) {
            maxSequence = end - start;
            maxEnd = end;
            maxStart = start;
            //cout << "Assigned " << maxStart << " " << maxEnd << endl;
        }
    }

    cout << "Max Sequence " << endl;
    for (int i = maxStart; i < maxEnd; i++) {
        cout << str[i];
    }
    cout << endl;
}
