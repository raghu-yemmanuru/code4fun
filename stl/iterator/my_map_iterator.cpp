#include <iostream>
#include <map>
#include <iterator>
#include <vector>

using namespace std;
typedef multimap<string,string> Map;

template<class Container>
class my_map_iterator : public iterator<input_iterator_tag,void,void,void,void> {
public:
    typedef Container container_type;
    typedef typename container_type::key_type key_type;
    typedef typename container_type::mapped_type mapped_type;
    typedef my_map_iterator<container_type> self_type;
    typedef vector<mapped_type> result_type;
private:
    container_type *mp_c;
    result_type m_v;
    typename container_type::iterator m_itr;
public:
    my_map_iterator(container_type &c): mp_c(&c){
        m_itr = mp_c->begin();
        operator++();
    }
    self_type& operator++(int) {
        self_type tmp = *this;
        operator++();
        return tmp;
    }
    result_type operator *() {
        return m_v;
    }
    self_type& operator++() {
        key_type k1;
        m_v.clear();
        if(m_itr != mp_c->end()) {
            k1 = m_itr->first;
            while(m_itr != mp_c->end() && m_itr->first == k1) {
                m_v.push_back(m_itr->second);
                m_itr++;
            }
        }
        return *this;
    }
};

int main() {
    Map m;
    string key,value;
    while(cin >> key >> value) {
        m.insert(make_pair(key,value));
    }
    my_map_iterator<Map > itr(m);
    my_map_iterator<Map >::result_type v = *itr;
    copy(v.begin(),v.end(),ostream_iterator<Map::mapped_type>(cout," "));
    cout << endl;
}
