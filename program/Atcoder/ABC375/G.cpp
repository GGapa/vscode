#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 2e5 + 5, mod = 998244853;
const LL INF = 1e18;

vector<array<int, 2>> G[N];

struct Dijkstra {
    using AI = array<LL, 2>;
    int n; vector<LL> dis, cnt;
    LL& operator[] (const int x) {return dis[x]; }
    Dijkstra() {}
    Dijkstra(int _n) : n(_n), dis(_n + 1, INF), cnt(_n + 1, 0) { }
    void init(int nn) {n = nn, dis.assign(n + 1, INF); cnt.assign(n + 1, 0); }
    void work(int st) {
        priority_queue<AI, vector<AI>, greater<AI>> q;
        fill(dis.begin(), dis.end(), INF);
        dis[st] = 0; q.push({0, st}); cnt[st] = 1;
        while(!q.empty()) {
            int x = q.top()[1], w = q.top()[0]; q.pop();
            if(dis[x] < w) continue;
            for(auto i : G[x]) {
                int to = i[0], w = i[1];
                if(dis[to] > dis[x] + w) {
                    dis[to] = dis[x] + w;
                    cnt[to] = cnt[x];
                    q.push({dis[to], to});
                }
                else if(dis[to] ==dis[x] + w) {
                    (cnt[to] += cnt[x]) %= mod;
                }
            }   
        }
    }
}dj1, dj2;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> E(1);
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w}), E.push_back({u, v, w});
    dj1.init(n); dj2.init(n);
    dj1.work(1); dj2.work(n);
    rep(i, 1, m) {
        int u = E[i][0], v = E[i][1], w = E[i][2];
        if((dj1[u] + w + dj2[v] == dj1[n] && dj1.cnt[u] * dj2.cnt[v] % mod == dj1.cnt[n]) || (dj1[v] + w + dj2[u] == dj1[n] && dj1.cnt[v] * dj2.cnt[u] % mod == dj1.cnt[n]) ) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}