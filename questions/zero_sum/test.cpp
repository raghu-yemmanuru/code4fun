#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef map<int,int> IndexMap;
typedef IndexMap::iterator IndexMapIter;

int main () {
    //int arr[] = {4,2,-3,1,6};
    //int arr[] = {4,2,0,1,6};
    int arr[] = {-3,2,3,1,6};
    vector<int> v (arr, arr+(sizeof(arr)/sizeof(int)));
    IndexMap m;
    int sumSoFar = 0;

    for(int i = 0; i < v.size(); i++) {
        sumSoFar += v[i];
        IndexMapIter itr = m.find(sumSoFar);
        if (itr != m.end()) {
            int start = itr->second + 1;
            int end = i;
            cout << "True" << endl;
            cout << "Index " << start << " " << end << endl;
            return 0;
        }
        m.insert(make_pair(sumSoFar, i));
    }

    cout << "False" << endl;
    return 0;
}
