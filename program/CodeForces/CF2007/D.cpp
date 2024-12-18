#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<VI> G(n + 1) ;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    string s; cin >> s; s = " " + s;    
    vector<int> cnt(n + 1), num(n + 1); 
    int ans = 0, t1 = 0, t2 = 0;
    function<void(int, int)> dfs1 = [&](int x, int fa) {
        cnt[x] = cnt[fa] + (s[x] != s[fa]);  num[x] = num[fa] + (s[x] == '?') ;
        if(G[x].size() == 1 && x != 1) {
            if(num[x] == 0 && (cnt[x] & 1) == 0) ans++;
            else if(num[x] != 0 && num[x] & 1) ans++;
            else if(s[x] == '?' && num[fa] & 1) t2++;
            else if(s[x] == '?' && (num[fa] & 1) == 0) t1++; 
        }
        for(auto to : G[x]) if(to != fa) dfs1(to, x);
    };
    dfs1(1, 0);
    ans += (t1 + 1) / 2, ans += t2 / 2;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
考虑到具体的问号其实并无作用。

*/