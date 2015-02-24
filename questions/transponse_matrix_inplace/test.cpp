#include <iostream>
#include <bitset>

using namespace std;

void printArray (int *a, int r, int c) {
    for (int i = 0; i < r*c; i++) {
        cout << a[i] << " ";
        if ((i+1)%c == 0) {
            //cout << endl;
        }
    }
    cout << endl;
}

void transpose(int *a, int r, int c) {
    int size = r*c-1;
    int cycleStart;
    int temp;
    int next;

    int i = 1;

    bitset<128> b;
    b.reset();
    b[0] = b[size] = 1;

    while (i < size) {
        temp = a[i];
        cycleStart = i;
        do {
            next = (i*r)%(size);
            swap(a[next],temp);
            b[i] = 1;
            i = next;
        } while (i != cycleStart);
        for (i = 1; i < size && b[i]; i++) ;
    }

    return;
}


int main () {
    int r=3,c=4;
    int *a = new int[r*c];

    for (int i = 0; i < r*c; i++) {
        a[i] = i+1;
    }

    printArray(a,r,c);
    transpose(a,r,c);
    //transpose(a,r,c);
    printArray(a,c,r);
    return 0;
}
