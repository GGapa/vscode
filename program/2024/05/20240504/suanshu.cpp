#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    stack<char> op; stack<int> v;
    unordered_map<char, int> mp{{'-', 1}, {'+', 1}, {'*', 2}, {'/', 2}};

    auto work = [&]() {
        int x2 = v.top(); v.pop();
        int x1 = v.top(); v.pop();
        char opt = op.top(); op.pop();
        if(opt == '+') x1 += x2;
        if(opt == '-') x1 -= x2;
        if(opt == '*') x1 *= x2;
        if(opt == '/') x1 /= x2;
        v.push(x1);
    };

    string num;
    for(auto c : s) {
        if(isdigit(c)) 
            num += c;
        else {
            if(num != "") v.push(atoi(num.c_str()));
            num = "";
            while(!op.empty() && mp[op.top()] >= mp[c]) work();
            op.push(c);            
        }
    }
    if(num != "") v.push(atoi(num.c_str()));
    while(op.size()) work();
    cout << v.top() << '\n';
    return 0;
}
