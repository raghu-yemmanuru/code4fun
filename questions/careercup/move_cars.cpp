#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
int const EMPTY = -1;

int findElement(vi &v, int element) {
    for(int i = 0; i < v.size(); i++) {
        if (v[i] == element) {
            return i;
        }
    }
    cout << "Messed up " << endl;
    return -2;
}

void printInstructions(vi &original, vi &required) {
    for (int i = 0; i < original.size(); i++) {
        if (original[i] == required[i]) {
            continue;
        }
        int empty_spot = findElement(original,EMPTY);
        cout << "Move car " << original[i] << " to position " << empty_spot << endl;
        int find_idx = findElement(original,required[i]);
        cout << "Move car " << original[find_idx] << " to position " << i << endl;
        original[empty_spot] = original[i];
        original[i] = original[find_idx];
        original[find_idx] = EMPTY;
    }
}

int main() {
    int num;
    cin >> num;
    vi original(num,0),required(num,0);
    for (int i = 0; i < num; i++) {
        cin >> original[i];
    }
    for (int i = 0; i < num; i++) {
        cin >> required[i];
    }
    printInstructions(original,required);
}
