#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<VI> G(n +1);
    for(int i = 1, u, v; i < n; i++)    
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    priority_queue<int, VI, greater<int>> q;
    q.push(1);
    vector<int> dis(n + 1, 1e9), vis(n + 1);
    function<void(int, int)> dfs = [&](int x, int fa) {
        dis[x] = dis[fa] + 1;
        if(!vis[x]) q.push(x);
        if(dis[x] == k) return ;
        for(auto to : G[x]) if(dis[x] + 1 < dis[to]) dfs(to, x);
    };
    vector<int> ans;
    dis[0] = -1;
    while(!q.empty()) {
        int x = q.top(); q.pop();
        if(vis[x]) continue;
        vis[x] = 1; dis[x] = 0;
        ans.emplace_back(x);
        dfs(x, 0);
    }
    for(auto i : ans) cout << i << " ";
    return 0; 
}