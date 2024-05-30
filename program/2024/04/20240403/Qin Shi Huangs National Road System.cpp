// Qin Shi Huang's National Road System UVA1494
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;
const int N = 1000 + 5;

int m; 
VI F;
double dis[N][N];

struct Edge {
    int u, v; 
    double w;
};
vector<Edge> G[N];

int find(int x) {
    if(F[x] == x) return x;
    return F[x] = find(F[x]);
}

void dfs(int x, int fa, double fal, VI &ess) {
    for(auto to : ess) dis[x][to] = dis[to][x] = max(dis[fa][to], fal);
    ess.push_back(x);
    for(auto i : G[x]) {
        int to = i.v;
        if(to != fa) dfs(to, x, i.w, ess);
    }
}

void solve() {
    cin >> m;
    F.resize(m + 1), iota(F.begin(), F.end(), 0);
    VI mst, ess;
    vector<array<int, 3>> A(m + 1);
    vector<Edge> es;
    rep(i, 1, m) cin >> A[i][0] >> A[i][1] >> A[i][2], G[i].clear();
    rep(i, 1, m) rep(j, i + 1, m) {
        double x = A[i][0] - A[j][0], y = A[i][1] - A[j][1];
        es.push_back({i, j, 1.0 * sqrt(x * x + y * y)});
    }
    sort(es.begin(), es.end(), [&](const Edge&x, const Edge& y) {
        return x.w < y.w;
    });
    int cnt = m - 1;
    double mt = 0, ans = -1;
    rep(i, 0, es.size() - 1) {
        auto e = es[i];
        int x = find(e.u), y = find(e.v);
        if(x == y) continue;
        F[x] = y; mt += e.w;
        G[e.u].push_back(e), G[e.v].push_back({e.v, e.u, e.w});
        if(--cnt == 0) break;
    }
    memset(dis, 0, sizeof(dis));
    dfs(1, -1, 0.0, ess);
    rep(i, 1, m) rep(j, i + 1, m) 
        ans = max(ans, 1.0 * (A[i][2] + A[j][2]) / (mt - dis[i][j]));
    printf("%.2f\n", ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}