#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<class T>
class pair_iterator: public iterator<output_iterator_tag, void, void, void, void> {
private:
    ostream *o_stream;
    const char *delim;
public:
    pair_iterator(ostream &os,const char *d = 0) : o_stream(&os),delim(d) {}
    pair_iterator& operator++() { return *this; }
    pair_iterator& operator++(int) { return *this; }
    pair_iterator& operator=(T &val) {
        *o_stream << val.first;
        if (delim) {
            *o_stream << delim;
        }
        *o_stream << val.second;
        if (delim) {
            *o_stream << delim;
        }
        return *this;
    }
    pair_iterator& operator*() {
        return *this;
    }
};

int main() {
    vector<pair<int,int> > vp;
    for (int i = 1; i < 10; i++) {
        vp.push_back(make_pair(i,i*10));
    }
    copy(vp.begin(),vp.end(),pair_iterator<pair<int,int> >(cout," "));
    cout << endl;
}
