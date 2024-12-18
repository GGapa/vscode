#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 200000 + 5, M = 200000 + 400000 + 10;

int n, m; 

struct Edge {
    int u, v, l, a;
};

vector<Edge> G[N], E; // 原本的图
vector<int> T[M];    // 最大生成树重构树
int A[M];            // 重构树节点的权重
int mn[M], F[M][23], nt[M][23];

namespace KruTree {
    int fa[M];
    int tot = 0;
    void init() {
        tot = 0;
        iota(fa, fa + 10 + n + m, 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    int work()  {
        init();
        sort(E.begin(), E.end(), [&](const Edge &x, const Edge&y) {
            return x.a > y.a;
        });
        for(auto e : E) {
            int x = find(e.u), y = find(e.v);
            if(x == y) continue;
            int id = n + ++tot;
            T[id].emplace_back(x), T[id].emplace_back(y);
            A[id] = e.a;
            fa[x] = id, fa[y] = id;
            if(tot == n - 1) break;
        }
        rep(i, 0, n) A[i] = 1e9;
        return find(1); 
    };
};

LL dis[N] ;     // 1 号节点到每一个节点的最小距离。

namespace Dijkstra {
    const LL INF = 1e18;
    using PI = pair<LL, int> ;
    void init() {
        fill(dis, dis + 1 + n, INF) ;
    }
    void work(int s) {
        priority_queue<PI, vector<PI>, greater<PI>> q;
        init();
        dis[s] = 0; q.push({0, s}) ;
        while(!q.empty()) {
            int x = q.top().second; LL vl = q.top().first; q.pop();
            if(dis[x] < vl) continue;
            for(auto i : G[x]) {
                int to = i.v, w = i.l;

                // cout << dis[to] << endl;
                if(dis[to] > dis[x] + w) {
                    dis[to] = dis[x] + w;
                    q.push({dis[to], to}) ;
                }
            }
        }
    }    
}

void init() {
    const int INF = 1e9;
    vector<Edge>(0).swap(E);
    rep(i, 0, n) vector<Edge>(0).swap(G[i]);
    rep(i, 0, n + m + 10) vector<int>(0).swap(T[i]);
    iota(mn, mn + 10 + n + m, INF);
    rep(i, 0, n + m + 10) fill(F[i], F[i] + 23, INF);
}

void dfs(int x, int fa) {
    F[x][0] = A[x]; nt[x][0] = fa;
    rep(i, 1, 21) nt[x][i] = nt[nt[x][i - 1]][i - 1], F[x][i] = min(F[x][i - 1], F[nt[x][i - 1]][i - 1]);
    if(1 <= x && x <= n) mn[x] = dis[x];
    for(auto to : T[x]) if(to != fa) dfs(to, x), mn[x] = min(mn[x], mn[to]); 
}

void solve() {
    cin >> n >> m; 
    init();
    for(int i = 1, u, v, l, a; i <= m; i++) 
        cin >> u >> v >> l >> a, G[u].push_back({u, v, l, a}), G[v].push_back({v, u, l, a}), E.push_back({u, v, l, a});
    int rt = KruTree::work();
    Dijkstra::work(1);
    dfs(rt, 0);
    int lstans = 0;
    int q, k, s; cin >> q >> k >> s;
    mn[0] = 0;
    for(int v, p; q--; ) {
        cin >> v >> p;
        v = (v + 1ll * k * lstans - 1) % n + 1;
        p = (p + 1ll * k * lstans) % (s + 1);
        per(i, 21, 0) {                        
            if(min(F[v][i], A[nt[v][i]]) > p)
                v = nt[v][i];
        }
        cout << (lstans = mn[v]) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}