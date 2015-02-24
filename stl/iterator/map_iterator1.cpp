#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

template <class Container>
class MyIterator : public iterator <input_iterator_tag,void,void,void,void> {
public:
typedef typename Container::mapped_type value_type;
typedef typename Container::key_type key_type;
typedef typename Container::iterator iterator_type;
typedef map<key_type,vector<value_type> > result_type;
private:
    Container *mp_map;
    iterator_type m_itr;
    result_type m_res;
    bool m_at_end;
public:
    MyIterator(Container &_c) {
        mp_map = &_c;
        m_itr = mp_map->begin();
        m_at_end = false;
        operator++();
    }
    result_type operator *() {
        return m_res;
    }
    const MyIterator operator++(int) {
        MyIterator tmp(*this);
        operator++();
        return tmp;
    }
    bool empty() {
        return m_at_end;
    }
    const MyIterator& operator++() {
        m_res.clear();
        key_type k1,k2;
        if (m_itr != mp_map->end()) {
            k1 = k2 = m_itr->first;
        }
        while(m_itr != mp_map->end() && k1 == k2) {
            m_res[k1].push_back(m_itr->second);
            m_itr++;
            if (m_itr == mp_map->end()) {
                break;
            }
            k2 = m_itr->first;
        }
        m_at_end = (m_res.size() == 0);
        return *this;
    }
};

int main() {
    multimap<string,string> mm;
    mm.insert(make_pair("abhi", "good boy"));
    mm.insert(make_pair("abhi","smart fellow"));;
    mm.insert(make_pair("abhi","innocent"));
    mm.insert(make_pair("harika","sweet person"));
    mm.insert(make_pair("harika","not feeling well"));
    mm.insert(make_pair("harika","running fever"));
    mm.insert(make_pair("raghu","working hard"));
    mm.insert(make_pair("raghu","short tempered"));

    MyIterator<multimap<string,string> > mi(mm);
    MyIterator<multimap<string,string> >::result_type r;
    while(!mi.empty()){
        r = *mi;
        MyIterator<multimap<string,string> >::result_type::iterator itr = r.begin();
        MyIterator<multimap<string,string> >::key_type k = itr->first;
        cout << k << ":" << endl;
        copy(r[k].begin(),r[k].end(),ostream_iterator<string>(cout," "));
        cout << endl;

        mi++;
    }
}
