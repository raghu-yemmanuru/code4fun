#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;
typedef vector<string> vs;
typedef map<string,int> Map;

void buildOperatorMap(Map &m) {
    m["+"] = 1;
    m["-"] = 1;
    m["*"] = 2;
    m["/"] = 2;

    return;
}
    
bool isOperator(const string &s, const Map &m) {
    return (m.find(s) != m.end());
}


int s2n(const string &s) {
    stringstream ss(s);
    int num;
    ss >> num;
    return num;
}

int Value(int lhs, int rhs, string op) {
    if (op == "+") {
        return (lhs + rhs);
    } else if (op == "-") {
        return (lhs-rhs);
    } else if (op == "*") {
        return (lhs*rhs);
    } else if (op == "/") {
        return (lhs/rhs);
    }
    return -1;
}

int evaluate(const string &s) {
    stringstream ss(s);
    string token;
    int result = 0;
    stack<int> st;
    Map m;
    buildOperatorMap(m);
    while (ss >> token) {
        if (!isOperator(token,m)) {
            st.push(s2n(token));
        } else {
            int rhs = st.top();
            st.pop();
            int lhs = st.top();
            st.pop();
            st.push(Value(lhs,rhs,token));
        }
    }
    return st.top();
}

int main() {
    string s;
    getline(cin,s);
    cout << "Evaluate " << evaluate(s) << endl;
}
