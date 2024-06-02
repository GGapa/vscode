// E
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
    struct Edge {
        int v, w;
    };
    vector<vector<Edge>> G(n  +1) ;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w, u--, v--, G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    priority_queue<array<ll, 2>> q;
    vector<ll> dis(n * 4 + 1, 1e17);
    dis[0] = 0; q.push({0, 0});
    while(!q.empty()) {
        int x = q.top()[1];
        ll d = -q.top()[0];
        q.pop();
        if(d > dis[x]) continue;
        int u = x / 4, a = x / 2 % 2, b = x % 2;
        for(auto i : G[u]){
            int y = i.v * 4 + a * 2 + b;
            if(dis[x] + i.w < dis[y]) {
                dis[y] = dis[x] + i.w;
                q.push({-dis[y], y});
            }
            if(a == 0 && dis[x] < dis[y + 2] ) {
                dis[y + 2] = dis[x];
                q.push({-dis[y + 2], y + 2});
            }
            if(b == 0 && dis[x] + i.w * 2 < dis[y + 1]) {
                dis[y + 1] = dis[x] + i.w * 2;
                q.push({-dis[y + 1], y + 1});
            } 
        }
    }
    rep(i, 1, n - 1) cout << min(dis[i * 4], dis[i * 4 + 3]) << " "; 
    return 0;
}