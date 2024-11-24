// 17:43
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9, N = 3e3 + 5;

vector<pair<int, int>> G[N];
int n, m;
int dis[N], vis[N], cnt[N], h[N];


bool spfa(int st) {
    fill(h, h + N, INF);
    queue<int> q;
    h[st] = 0; q.push(st); vis[st] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = 0;
        for(auto i : G[x]){ 
            int to = i.first, w = i.second;
            if(h[to] <= h[x] + w) continue;
            h[to] = h[x] + w;
            if(vis[to]) continue;
            vis[to] = 1;
            q.push(to); 
            cnt[to] = cnt[x] + 1;
            if(cnt[to] > n) return false;
        }
    }
    return true;    
}

void dijkstra(int st) {
    fill(dis, dis + 1 + n, INF) ;
    using AI = array<int, 2>;
    priority_queue<AI, vector<AI>, greater<AI>> q;
    dis[st] = 0; q.push({0, st}) ;
    while(!q.empty()) {
        int x = q.top()[1], w = q.top()[0]; q.pop();
        // cerr << x << '\n';
        if(dis[x] < w) continue;
        for(auto i : G[x]){ 
            int to = i.first, w = i.second;
            if(dis[to] <= dis[x] + w) continue;
            dis[to] = dis[x] + w;
            q.push({dis[to], to});
        }
    }
} 


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, G[u].emplace_back(v, w);
    rep(i, 1, n) G[0].emplace_back(i, 0);
    if(!spfa(0)) return cout << -1 << '\n' ,0;
    rep(i, 1, n) for(auto &j : G[i]) j.second += h[i] - h[j.first];
    rep(i, 1, n) {
        dijkstra(i);
        LL ans = 0;
        // rep(j, 1, n) cerr << dis[j] << " \n"[j == n];
        rep(j, 1, n) {
            if(dis[j] != INF) ans += 1ll * j * (dis[j] -h[i] + h[j]);
            else  ans += 1ll * j * dis[j];
        }
       cout << ans << '\n';
    }
    return 0;
}
