#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<VI> G(n + 1);
    for(int i = 2, u, v; i <= n; i++)
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    if(n <= 2) return cout << 0 << '\n', void();
    
    vector<int> vis(n + 1), id(n + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), [&](const int x, const int y) {
        return G[x].size() > G[y].size();
    });

    int ans = 0;
    rep(x, 1, n) {
        for(auto to : G[x]) vis[to] = 1;

        for(auto a : id) {
            if(a == 0 || a == x) continue;
            if(ans >= (int)G[x].size() + (int)G[a].size() - 1) break;
            ans = max(ans, (int)G[x].size() + (int)G[a].size() - 1 - vis[a]);
        }
        
        for(auto to : G[x]) vis[to] = 0;
    } 
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}