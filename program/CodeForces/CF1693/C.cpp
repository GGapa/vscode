#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> G(n + 1);

    const LL INF = 1e18;
    vector<int> deg(n + 1); vector<LL> dis(n + 1, INF);
    priority_queue<pair<LL, int>> q;
    for(int i = 1, u, v; i <= m; i++)   
        cin >> u >> v, G[v].emplace_back(u), deg[u]++; 
    q.push({0, n}); dis[n] = 0;
    while(!q.empty()) {
        int x = q.top().second; LL val = -q.top().first;
        q.pop();
        if(dis[x] < val) continue;
        // cerr     << x << '\n';
        for(auto to : G[x]) {
            int w = deg[to]--;
            if(dis[to] > dis[x] + w) dis[to] = dis[x] + w, q.push({-dis[to], to});
        }
    }
    cout << dis[1] << '\n';
    return 0;
}