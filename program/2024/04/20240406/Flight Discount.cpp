// Flight Discount
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using AI = array<int, 2>;
const ll INF = 1e17;

struct Dijkstra {
    vector<vector<AI>> G;
    vector<array<int, 3>> es;
    vector<ll> D;
    int n;
    Dijkstra(int _n) : G(_n + 1), n(_n), D(_n + 1, INF){}
    void add(int u, int v, int w) {
        G[u].push_back({v, w}), es.push_back({u, v, w});
    }
    void solve(int s) {
        D[s] = 0;
        priority_queue<AI, vector<AI>, greater<AI>> q;
        q.push({0, s});
        while(!q.empty()) {
            int x = q.top()[1], d = q.top()[0]; q.pop();
            if(D[x] < d) continue;
            for(auto i : G[x]) {
                int nd = i[1] + D[x], to = i[0];
                if(nd < D[to]) {
                    D[to] = nd, q.push({nd, to});
                }
            }
        }
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    Dijkstra dj1(n), dj2(n);
    for(int u, v, w, i = 1; i <= m; i++) 
        cin >> u >> v >> w, dj1.add(u, v, w), dj2.add(v, u, w);
    dj1.solve(1), dj2.solve(n);
    ll ans = INF;
    for(auto e : dj1.es) {
        ans = min(ans, e[2] / 2  + dj1.D[e[0]] + dj2.D[e[1]]);
    }
    cout << ans << '\n';
    return 0;
}