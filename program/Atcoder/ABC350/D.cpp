#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> G(n  +1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    VI vis(n + 1), t;
    function<void(int)> dfs = [&](int x) {
        vis[x] = true; 
        t.push_back(x);
        for(auto to : G[x]) if(!vis[to]) 
            dfs(to);
    };
    ll ans = 0;
    rep(i, 1, n) if(!vis[i] && G[i].size() != 0) {
        t.clear();
        dfs(i);
        ll tmp = 0;
        for(auto i : t) tmp += (t.size() - 1 - G[i].size());
        ans += tmp / 2;
    }
    cout << ans << '\n';
    return 0;
}