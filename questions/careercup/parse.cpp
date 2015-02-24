#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;
typedef vector<string> vs;
typedef map<string,int> Map;

void buildMap(Map &m) {
    m[")"] = 0;
    m["("] = 0;
    m["+"] = 1;
    m["-"] = 1;
    m["*"] = 2;
    m["/"] = 2;
}
int s2n(string &s) {
    stringstream ss(s);
    int num;
    ss >> num;
    return num;
}

bool isOperator(string s, Map &m) {
    return (m.find(s) != m.end());
}

vs parse(const string &s, Map &m) {
    stringstream ss(s);
    char ch;
    vs v;
    string temp;
    while (ss >> ch) {
        if (isOperator(string(1,ch),m)) {
            if (temp.size()) {
                v.push_back(temp);
                temp = "";
            }
            v.push_back(string(1,ch));
        } else {
            temp.push_back(ch);
        }
    }
    if (temp.size()) {
        v.push_back(temp);
    }
    return v;
    //copy(v.begin(), v.end(), ostream_iterator<string>(cout,"\n"));
}

vs postFix(const vs &v, Map &m) {
    stack<string> s;
    vs postV;
    for (int i = 0; i < v.size(); i++) {
        if (!isOperator(v[i],m)) {
            postV.push_back(v[i]);
            continue;
        }
        if (v[i] == "(") {
            s.push(v[i]);
        } else if (v[i] == ")") {
            while(s.top() != "(") {
                postV.push_back(s.top());
                s.pop();
            }
            s.pop();
        } else if (s.empty() || m[s.top()] < m[v[i]]) {
            s.push(v[i]);
        } else {
            while (!s.empty() && m[s.top()] >= m[v[i]]) {
                postV.push_back(s.top());
                s.pop();
            }
            s.push(v[i]);
        }
    }
    while(!s.empty()) {
        postV.push_back(s.top());
        s.pop();
    }
    return postV;
}

int resultOp(int lhs, int rhs, string op) {
    if (op == "+") {
        return (lhs+rhs);
    } else if (op == "-") {
        return (lhs-rhs);
    } else if (op == "*") {
        return (lhs*rhs);
    } else if (op == "/") {
        return lhs/rhs;
    }
    cout << "Invalid Operator!!!" << endl;
    return -1;
}

int evaluate(vs &v, Map &m) {
    stack<int> s;
    for (int i = 0; i < v.size(); i++) {
        if (!isOperator(v[i],m)) {
            s.push(s2n(v[i]));
        } else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(resultOp(b,a,v[i]));
        }
    }
    return s.top();
}

int main() {
    string s;
    cin >> s;
    Map m;
    buildMap(m);
    vs v = parse(s,m);
    copy(v.begin(),v.end(),ostream_iterator<string>(cout," "));
    cout << endl;
    vs vp = postFix(v,m);
    copy(vp.begin(),vp.end(),ostream_iterator<string>(cout," "));
    cout << endl;
    cout << "Result is " << evaluate(vp,m) << endl;
}

