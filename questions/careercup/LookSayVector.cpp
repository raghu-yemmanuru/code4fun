#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vi;

vi countNumbers(const vi &in) {
    vi result;
    int i = 0;
    int count;
    int num;
    while(i < in.size()) {
        num = in[i];
        count = 1;
        while(i < in.size()-1 && in[i] == in[i+1]) {
            count++;
            i++;
        }
        result.push_back(count);
        result.push_back(num);
        i++;
    }
    return result;
}

int main() {
    vi in,result;
    int num;
    while(cin >> num) {
        in.push_back(num);
    }
    result = countNumbers(in);
    copy(result.begin(),result.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
