#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;
typedef vector<string> vs;
typedef map<string,int> Map;

int s2n(string &s) {
    stringstream ss(s);
    int num;
    ss >> num;
    return num;
}

string n2s (int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

void parse(string s, vs &v) {
    stringstream ss(s);
    int lhs,rhs;
    char op;
    stringstream nums;
    while(ss >> lhs) {
        v.push_back(n2s(lhs));
        if (ss >> op) {
            v.push_back(string(1,op));
        }
    }
    return;
}

void Precedence(Map &m) {
    m["-"] = 0;
    m["+"] = 0;
    m["*"] = 1;
    m["/"] = 1;
}


bool isOperator(string &s, Map &m) {
    if (m.find(s) != m.end()) {
        return true;
    }
    return false;
}

bool isOperand(string &s, Map &m) {
    return !isOperator(s, m);
}

vs postFix(vs &v, Map &m) {
    vs result;
    stack<string> s;
    for (int i = 0; i < v.size(); i++) {
        if (isOperand(v[i],m)) {
            result.push_back(v[i]);
        } else {
            if (s.empty() || m[v[i]] > m[s.top()]) {
                s.push(v[i]);
            } else {
                result.push_back(s.top());
                s.pop();
                s.push(v[i]);
            }
        }
    }
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int findVal(int lhs, int rhs, string op) {
    if (op == "+") {
        return (lhs + rhs);
    } else if (op == "-") {
        return (lhs - rhs);
    } else if(op == "*") {
        return (lhs * rhs);
    } else if (op == "/") {
        return lhs/rhs;
    }
    return -1;
}

int evaluate(vs &post, Map &m) {
    int result = 0;
    stack<string> s;
    for (int i = 0; i < post.size(); i++) {
        if (isOperand(post[i],m)) {
            s.push(post[i]);
        } else {
            int rhs = s2n(s.top());
            s.pop();
            int lhs = s2n(s.top());
            s.pop();
            s.push(n2s(findVal(lhs,rhs,post[i])));
        }
    }
    return s2n(s.top());
}

int main() {
    vs vin,vpost;
    string s;
    getline(cin,s);
    Map m;
    Precedence(m);
    parse(s,vin);
    vpost = postFix(vin, m);
    int ret = evaluate(vpost,m);

    copy(vpost.begin(),vpost.end(),ostream_iterator<string>(cout," "));
    cout << endl;

    cout << "result " << ret << endl;
}
