//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int INF = 1e9, N = 10000  + 6;
int n, m; 
struct Node {
    int v, w;
};
vector<Node> G[N];

string spfa(int st) {
    vector<int>  vis(n + 1), cnt(n + 1);
    vector<int> dis(n + 1, -INF);
    queue<int> q;
    q.push(st); 
    dis[st] = 0; vis[st] = 1;
    while(!q.empty()) {
        if(clock() * 1.0 / CLOCKS_PER_SEC * 1000 > 970) return "No";
        int x = q.front(); q.pop();
        vis[x] = 0;
        for(auto i : G[x]) if(dis[x] + i.w > dis[i.v] ){
            dis[i.v] = dis[x] + i.w;
            if(!vis[i.v]) {
                vis[i.v] = 1;
                q.push(i.v);
                if(++cnt[i.v] >= n + 1) return "No";
            }
        }
    }
    return "Yes";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, x, a, b, c; i <= m; i++)  {
        cin >> x >> a >> b;
        if(x == 1) cin >> c, G[b].push_back({a, c});
        if(x == 2) cin >> c, G[a].push_back({b, -c});
        if(x == 3) G[a].push_back({b, 0}), G[b].push_back({a, 0});
    }
    rep(i, 1, n) G[0].push_back({i, 0});
    cout << spfa(0) << '\n';
    return 0;
}