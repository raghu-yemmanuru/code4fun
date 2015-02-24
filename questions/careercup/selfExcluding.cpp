#include<iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vi;

int random_num() {
    return 1+(rand()%5);
}

vi selfProduct(vi &v) {
    vi left(v.size(),1), right(v.size(),1);
    for (int i = 1; i < v.size(); i++) {
        left[i] = v[i-1]*left[i-1];
    }
    for (int i = v.size()-2; i >= 0; i--) {
        right[i] = v[i+1]*right[i+1];
    }

    vi result(v.size(),0);
    for (int i = 0; i < v.size(); i++) {
        result[i] = left[i]*right[i];
    }
    return result;

}

int main() {
   vi v(4); 
   srand(time(NULL));
   generate(v.begin(),v.end(),random_num);

   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
   cout << endl;

   vi result = selfProduct(v);
   copy(result.begin(),result.end(),ostream_iterator<int>(cout," "));
   cout << endl;
}
