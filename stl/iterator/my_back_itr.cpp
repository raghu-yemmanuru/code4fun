#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int random_num() {
    return rand()%10;
}

template<class Container>
class my_back_insert_iterator : public iterator<output_iterator_tag,void,void,void,void> {
private:
    typedef Container container_type;
    typedef my_back_insert_iterator<container_type> self_type;
    container_type *m_pc;
public:
    typedef typename container_type::value_type value_type;
    my_back_insert_iterator(container_type &x) : m_pc(&x){}
    self_type& operator = (const value_type &v) {
        m_pc->push_back(v);
        return *this;
    }
    self_type& operator ++(int) {
        return *this;
    }
    self_type& operator ++() {
        return *this;
    }
    self_type& operator *() {
        return *this;
    }
};

template<class Container>
my_back_insert_iterator<Container> my_back_inserter(Container &x) {
    return my_back_insert_iterator<Container>(x);
}

int main() {
    vi v(10),v2;
    srand(time(NULL));
    generate(v.begin(),v.end(),random_num);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    copy(v.begin(),v.end(),my_back_inserter(v2));
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
