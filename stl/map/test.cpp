#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class WidgetKey {
    public:
        int id;
        WidgetKey(int _id): id(_id) {}
};

class compareKeys: public binary_function<WidgetKey &, WidgetKey&, bool> {
    public:
        bool operator() (const WidgetKey &lhs, const WidgetKey &rhs) {
            return lhs.id < rhs.id;
        }
};

class Widget {
    public:
        int data;
        Widget (int _data): data(_data) {}
};

int main() {
    /*vector <int> numbers;
    map <WidgetKey, Widget, compareKeys> widgets;

    numbers.reserve(10);
    for (int i = 0; i < 10; i++) numbers.push_back(i);
    random_shuffle(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        cout << "Inserting id " << numbers[i] << endl;
        widgets.insert(make_pair(WidgetKey(numbers[i]), Widget(i+10)));
    }

    for(map<WidgetKey,Widget>::iterator itr = widgets.begin();
        itr != widgets.end(); itr++) {
        cout << itr->first.id << " " << itr->second.data << endl;
    }*/

    map<string,int> m;
    string s1 ("abcd");
    string s2 ("abcd");
    string s3 ("abcd");
    m[s1] += 1;
    m[s2] += 1;
    m[s3] += 1;

    for (map<string,int>::iterator itr = m.begin(); itr != m.end(); itr++) {
        cout << " " << itr->first << " " << itr->second << endl;
    }


    return 0;
}
