#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

void permute(vi input,vi output, int curSum, int target) {
    if (curSum == target) {
        copy(output.begin(),output.end(),ostream_iterator<int>(cout," "));
        cout << endl;
        return;
    }
    if (curSum > target) {
        return;
    }
    for (int i = 0; i < input.size(); i++) {
        //vi temp(input.begin(),input.begin()+i);
        vi temp(input.begin()+i+1,input.end());
        output.push_back(input[i]);
        permute(temp,output,curSum + input[i], target);
        output.pop_back();
    }
}

void printSubsets(vi &v, int sum) {
    vi result;
    permute(v,result,0,sum);
}

int main() {
    vi v;
    for (int i = 1; i <= 6; i++) {
        v.push_back(i);
    }
    printSubsets(v,7);
}
