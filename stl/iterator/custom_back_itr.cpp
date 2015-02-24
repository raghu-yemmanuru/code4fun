#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


template<class Container>
//To make it a iterator need to derive from iterator class to carry iterator_traits
class custom_back_insert_iterator : public iterator<output_iterator_tag,void,void,void,void>
{
public:
    Container *container;
    custom_back_insert_iterator(Container &x) : container(&x) {}
    // This is a pre-increment variation. so, increment and return reference to self
    custom_back_insert_iterator& operator++() {
        return *this;
    }
    //This is a post-increment variation. so, return a copy before increment
    custom_back_insert_iterator operator++(int) {
        custom_back_insert_iterator tmp(*this);
        operator++();
        return tmp;
    }
    //typename should be used when to define a new type based on template parameter
    custom_back_insert_iterator& operator=(typename Container::const_reference value) {
        container->push_back(value);
        return *this;
    }
    custom_back_insert_iterator& operator*() {
        return *this;
    }
};


template<class Container>
custom_back_insert_iterator<Container> custom_back_inserter(Container &x) {
    return custom_back_insert_iterator<Container> (x);
}

int main() {
    vector<int> v1,v2;
    for (int i = 1; i < 5; i++) {
        v1.push_back(i);
        v2.push_back(i*10);
    }

    copy(v1.begin(), v1.end(), custom_back_inserter(v2));
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

