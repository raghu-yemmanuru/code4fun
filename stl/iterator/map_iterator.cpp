#include <iostream>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

class Widget {
public:
    int id;
    Widget(int _id):id(_id){}
};

template <class Container>
class MapIterator:public iterator<input_iterator_tag,void,void,void,void> {
private:
    Container *mp_c;
    typename Container::iterator itr;
    vector<typename Container::mapped_type> v;
public:
    MapIterator(Container &c) {
        mp_c = &c;
        itr = c.begin();
        operator++();
    }
    vector<typename Container::mapped_type> operator*() {
        return v;
    }
    const MapIterator<Container>& operator++(int) {
        MapIterator<Container> tmp(*this);
        operator++();
        return tmp;
    }
    const MapIterator<Container>& operator++() {
        typename Container::key_type k1,k2;
        v.clear();
        if (itr == mp_c->end()) {
            return *this;
        }

        k1 = k2 = itr->first;
        while (k1 == k2) {
            v.push_back(itr->second);
            itr++;
            if (itr == mp_c->end())
                break;
            k2 = itr->first;
        }
        return *this;
    }
};

int main() {
    multimap<string,int> mm;
    mm.insert(make_pair("hello",1));
    mm.insert(make_pair("hello",2));
    mm.insert(make_pair("hello",3));
    mm.insert(make_pair("hi",1));
    MapIterator<multimap<string,int> > mit(mm);
    vector<int> v = *mit;
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    ++mit;
    v = *mit;
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
