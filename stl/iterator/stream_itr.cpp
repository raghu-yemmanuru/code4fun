#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

int main() {
    vector<int> v;
    v.reserve(100);
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        v.push_back(rand()%1000);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    copy (v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;

    fstream fs("test.txt", fstream::out);
    copy (v.begin(), v.end(), ostream_iterator<int>(fs,"\n"));
    fs.close();

    int val;
    fstream fs1("test.txt", fstream::in);
    while(fs1 >> val) {
        cout << val << " ";
    }
    fs1.close();

    /*int val1, val2, val3, val4;
    fstream fs1("test.txt", fstream::in);
    cout << (fs1 >> val1) << " ";
    cout << (fs1 >> val2) << " ";
    cout << (fs1 >> val3) << " ";
    cout << val1 << " " << val2 << " " << val3;*/

    cout << endl;
}
