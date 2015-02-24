#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
typedef map<string,pair<string,string> > Map;
typedef vector<pair<string,int> > Vector;

int main() {
    string time,function,type;
    Map m;
    Vector v;
    int indent = 0;
    while (cin >> time >> function >> type) {
        if (type == "enter") {
            v.push_back(make_pair(function,indent++));
            m[function].first = time;
        } else if (type == "exit") {
            m[function].second = time;
            indent--;
        }
    }
    stringstream ss;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            cout << "   ";
        }
        ss << v[i].first << " ( " << m[v[i].first].first << " - " << m[v[i].first].second << ")";
        cout << ss.str();
        cout << endl;
        ss.str("");
    }
}
   
        
