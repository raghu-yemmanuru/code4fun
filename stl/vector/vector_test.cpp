#include <iostream>
#include <vector>
using namespace std;

bool isOdd (int i) {
    return i%2;
}

struct node {
    int x;
    node(int _x):x(_x){}
};

int main() {
    /*vector<int> vec;
    vec.reserve(10);
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }*/

    // Range insertion
    //vector<int> vec2;
    //vec2.insert(vec2.begin(),vec.begin()+vec.size()/2,vec.end());
    //vec = vector<int>(vec2.begin(),vec2.end());

    // Range erase
    //vec.erase(vec.begin()+vec.size()/2,vec.end());

    // Remove Erase Idiom
    // First call remove on a vector with specific value
    // As a side effect it will remove all the elements in the vector and
    // returns new end. From that new end to the previous end, erase them
    //vec.erase(remove(vec.begin(), vec.end(), 5), vec.end());

    // remove_if use
    // by providing a predicate we can remove elements we dont need
    //vec.erase(remove_if(vec.begin(), vec.end(), isOdd), vec.end());

    // construct vector from array elements
    //int arr[] = {1,2,3,4};
    //vec = vector<int>(arr, arr + sizeof(arr)/sizeof(int));

    /*for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << endl;*/

    vector<node> vn;
    node n(0);
    vn.push_back(n);
    vector<node>::iterator it;

    it = vn.begin();
    cout << (*it).x << endl;
}
