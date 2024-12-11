// P7073 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

struct Node {
    int l, r, v, x;
    char op = 0;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; getline(cin, s);
    int n, idx = 0; cin >> n;
    vector<int> V(n + 1);
    vector<Node> T(1e6);
    rep(i, 1, n) cin >> V[i];
    int q; cin >> q;
    stack<int> st;
    auto pop = [&](int &x) {x = st.top(), st.pop();};
    for(stringstream ss(s); ss >> s; ) {
        auto c = s[0];
        Node &a = T[++idx];
        a.op = c;
        if(c == 'x') a.v = V[a.x = stoi(s.substr(1))];
        if(c == '!') pop(a.l), a.v = !T[a.l].v;
        if(c == '&') pop(a.l), pop(a.r), a.v = T[a.l].v & T[a.r].v;
        if(c == '|') pop(a.l), pop(a.r), a.v = T[a.l].v | T[a.r].v;
        st.push(idx);
    }
    vector<int> C(n + 2);
    auto dfs = [&](auto self, Node &a) -> void {
        auto &ls = T[a.l], &rs = T[a.r];
        if(a.op == 'x') C[a.x] = 1;
        if(a.op == '!') self(self, ls);
        if(a.op == '&') {
            if(ls.v) self(self, rs);
            if(rs.v) self(self, ls);
        }
        if(a.op == '|') {
            if(!ls.v) self(self, rs);
            if(!rs.v) self(self, ls);
        }
    };
    auto &r = T[st.top()];
    dfs(dfs, r);
    for(int i = 1, x; i <= q; i++) 
        cin >> x, cout << (C[x] ? !r.v : r.v) << '\n';
    return 0;
}