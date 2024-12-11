#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int INF = 1e9, N = 100000 + 6;
int n, m; 
struct Node {
    int v, w;
};
vector<Node> G[N];

ll spfa(int st) {
    vector<int>  vis(n + 1), cnt(n + 1);
    vector<ll> dis(n + 1, -1e18);
    queue<int> q;
    q.push(st); 
    dis[st] = 0; vis[st] = 1;
    while(!q.empty()) {
        // if(clock() * 1.0 / CLOCKS_PER_SEC * 1000 > 970) return -1;
        int x = q.front(); q.pop();
        vis[x] = 0;
        for(auto i : G[x]) if(dis[x] + i.w > dis[i.v] ){
            dis[i.v] = dis[x] + i.w;
            if(!vis[i.v]) {
                vis[i.v] = 1;
                q.push(i.v);
                if(++cnt[i.v] >= n + 1) return -1;
            }
        }
    }
    ll ret = 0;
    rep(i, 0, n) ret += dis[i];
    return ret;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, x, a, b; i <= m; i++) {
        cin >> x >> a >> b;
        if(x == 1) G[a].push_back({b, 0}), G[b].push_back({a, 0});
        if(x == 2) {G[a].push_back({b, 1}); if(a == b) return cout << -1, 0;};
        if(x == 3) G[b].push_back({a, 0});
        if(x == 4) {G[b].push_back({a, 1}); if(a == b) return cout << -1, 0;};
        if(x == 5) G[a].push_back({b, 0});
    }
    rep(i, 1, n) G[0].push_back({i, 1});
    cout << spfa(0) << '\n';
    // cout << -1 << '\n';
    return 0;
}