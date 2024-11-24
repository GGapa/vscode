#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5;
set<int> G[N];
 
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n) G[i].clear();
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        if(u > v) swap(u, v);
        G[u].insert(v), G[v].insert(u);
    }

    vector<array<int, 3>> ans;
    rep(i, 1, n) {
        while(G[i].size() > 1) {
            int x = *G[i].begin(); G[i].erase(G[i].begin());
            int y = *G[i].begin(); G[i].erase(G[i].begin());
            if(G[x].count(y)) G[x].erase(y), G[y].erase(x);
            else G[x].insert(y), G[y].insert(x);
            ans.push_back({i, x, y});
            G[x].erase(i), G[y].erase(i);
        }
    }
    vector<pair<int, int>> edg;
    vector<int> vis(n + 1);

    rep(i, 1, n) for(auto to : G[i]) if(to > i) edg.emplace_back(i, to), vis[i] = vis[to] = 1; 

    rep(i, 1, n) if(!vis[i] && edg.size()) {
        int x = edg.back().first, y = edg.back().second;
        edg.pop_back();
        edg.emplace_back(i, x);
        ans.push_back({i, x, y});
    }

    while(edg.size() > 1) {
        int x = edg.back().first, y = edg.back().second; edg.pop_back();
        int a = edg.back().first, b = edg.back().second; edg.pop_back();
        ans.push_back({x, y, a});
        edg.push_back({x, a});
    }

    cout << ans.size() << '\n';
    for(auto a : ans) cout << a[0] << " " << a[1] << " " << a[2] << '\n';
 }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
如果一个图能全部清空，
*/