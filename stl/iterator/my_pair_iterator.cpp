#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
typedef pair<int,int> Pair;
typedef vector<Pair > vp;

template<class T>
class my_pair_iterator: public iterator<output_iterator_tag,void,void,void,void> {
private:
    ostream *mp_os;
    const char *delim1;
    const char *delim2;
    typedef my_pair_iterator<T> self_type;
public:
    typedef T value_type;
    my_pair_iterator(ostream &os, const char* _d1 = 0, const char* _d2 = 0):
        mp_os(&os),delim1(_d1),delim2(_d2){}
    self_type& operator++() {
        return *this;
    }
    self_type& operator++(int) {
        return *this;
    }
    self_type& operator *() {
        return *this;
    }
    self_type& operator =(value_type &v) {
        if (delim1) {
            *mp_os << delim1; 
        }
        *mp_os << v.first << "," << v.second;
        *mp_os << v.first;
        if (delim2) {
            *mp_os << delim2 << " ";
        }
        return *this;
    }
};

int main() {
    vp v;
    for (int i = 0; i < 10; i++) {
        v.push_back(make_pair(i,i+1));
    }
    copy(v.begin(),v.end(), my_pair_iterator<Pair >(cout,"<",">"));
    cout << endl;
}
