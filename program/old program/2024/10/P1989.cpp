#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;
vector<int> G[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> deg(n + 1), u(m + 1), v(m + 1), id(n); 
    rep(i, 1, m) cin >> u[i] >> v[i], deg[u[i]]++, deg[v[i]]++;
    rep(i, 1, m) {
        int x = u[i], y = v[i];
        if(deg[x] == deg[y] && x > y || deg[x] > deg[y]) swap(u[i], v[i]);
        x = u[i], y = v[i];
        G[x].emplace_back(y);
    }
    vector<int> vis(n + 1);
    int ans = 0;
    rep(i, 1, n) {
        for(auto j : G[i]) vis[j] = 1;
        for(auto j : G[i]) for(auto k : G[j]) if(vis[k]) ans++;
        for(auto j : G[i]) vis[j] = 0;
    }
    cout << ans << '\n';
    return 0;
}