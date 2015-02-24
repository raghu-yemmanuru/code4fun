#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;

void mutate(string &s, vi &v) {
    vb visited(v.size(),false); 
    char cur_element,future_element;
    int cur_index, future_index;
    for (int i = 0; i < v.size(); i++) {
        if (visited[i]) {
            continue;
        }
        cur_index = i;
        cur_element = s[i];
        do {
            future_index = v[cur_index];
            future_element = s[future_index];
            s[future_index] = cur_element;
            cout << future_index << " " << cur_element << endl;
            visited[cur_index] = true;

            cur_index = future_index;
            cur_element = future_element;
        } while(!visited[cur_index]);
    }
    return;
}

int main() {
    string s;
    cin >> s;
    int num;
    vi v;
    while(cin >> num) {
        v.push_back(num);
    }
    mutate(s,v);
    cout << s << endl;
}
