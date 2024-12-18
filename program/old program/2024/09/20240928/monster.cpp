#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 11;

vector<int> G[N];
int w[N], A, B;
int dis[N];
int n, m;

namespace work1 {
    void main() {
        fill(dis, dis + 1 + n, n + 10);
        dis[1] = 0; queue<int> q; q.push(1);
        A -= B;
        while(q.size()) {
            int x = q.front(); q.pop();
            for(auto to : G[x]) if(dis[x] + 1 < dis[to]) {
                if(w[1] + 1ll * A * dis[x] > w[to]) q.push(to), dis[to] = dis[x] + 1;
            }
        }       
        cout << (dis[n] == n + 10? -1 : dis[n]) << '\n';
    }
}; 

namespace work2 {
    int nd[N]; bool vis[N];
    using AI = array<int, 2>;
    bool check() {
        fill(vis, vis + 1 + n, 0);
        priority_queue<AI, vector<AI>, greater<AI>> q;
        for(auto to : G[1]) q.push({w[to], to}), vis[to] = 1;
        vis[1] = 1;
        rep(i, 0, n) {
            if(q.empty()) 
                return false;
            int x = q.top()[1]; q.pop();
            if(nd[x] > i)  return false;
            if(x == n) return true;
            for(auto to : G[x]) if(vis[to] == false) 
                q.push({w[to], to}), vis[to] = true;
        }
         return false;
    }
    void main() {
        fill(nd, nd + 1 + n, 0); fill(dis, dis + 1 + n, n + 10);
        rep(i, 2, n) nd[i] = (w[i] < w[1] ? 0 : (w[i] - w[1] + A - B) / (A - B));
        if(!check()) return cout << -1 << '\n', void();
        priority_queue<AI, vector<AI>, greater<AI>> q;
        dis[1] = 0; q.push({0, 1});
        fill(vis, vis + 1 + n, 0);
        while(!q.empty()) {
            int x = q.top()[1], ww = q.top()[0]; q.pop();
            if(vis[x]) continue;
            vis[x] = 1;
            for(auto to : G[x]) {
                if(dis[to] > max(dis[x], nd[to]) + 1) {
                    dis[to] = max(dis[x], nd[to]) + 1;
                    q.push({dis[to], to});
                }
            }
        }
        cout << (dis[n] == n + 10? -1 : dis[n]) << '\n';
    }
};

void solve() {
    cin >> n >> m >> A >> B;
    rep(i, 0, n) vector<int>(0).swap(G[i]);             
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    rep(i, 1, n) cin >> w[i];
    rep(i, 2, n) w[i] += B;
    if(n == 1) return cout << 0 << '\n', void();
    if(A <= B) return work1::main();
    else work2::main();
}

signed main() {
    freopen("monster.in", "r", stdin);
    freopen("monster.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}/*
考虑到 A <= B 的情况是简单的
1
5 4 8 8
1 2
1 3
1 4
4 5
15 1 1 14 15
*/
