#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 2e5 + 5;

namespace MCMF {
    constexpr LL INF = 1e18;
    struct E {
        int v; LL w, c;
        E(int v = 0, LL w = 0, LL c = 0) : v(v), w(w), c(c) {}
    };
    vector<E> e;
    vector<int> G[N];
    void addE(int u, int v, LL w, LL c) {
        G[u].emplace_back(e.size());
        e.emplace_back(v, w, c);
    }
    int add(int u, int v, LL w, LL c) {
        addE(u, v, w, c); addE(v, u, 0, -c);
        return (int)e.size() - 2;
    }

    int n = -1;
    int vis[N], pre[N];
    LL dis[N], in[N];
    void init(int nn) {n = nn; }
    bool bfs(int s, int t) {
        fill(dis, dis + 1 + n, INF);
        queue<int> q;
        dis[s] = 0; q.push(s);  vis[s] = 1; in[s] = INF;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            vis[x] = 0;
            for(auto i : G[x]) {
                auto [to, w, c] = e[i];
                if(dis[to] > dis[x] + c && w) {
                    dis[to] = dis[x] + c; pre[to] = i;
                    in[to] = min(in[x], w);
                    if(!vis[to]) q.emplace(to), vis[to] = 1;
                }
            }
        }
        return dis[t] < INF;
    }
    array<LL, 2> work(int s, int t) {
        assert(n != -1); 
        LL flow = 0, cost = 0;
        while(bfs(s, t)) {
            flow += in[t];
            int x = t;
            while(x != s) {
                cost += in[t] * e[pre[x]].c;
                e[pre[x]].w -= in[t];
                e[pre[x] ^ 1].w += in[t];
                x = e[pre[x] ^ 1].v;
            }
        }
        return {flow, cost};
    }
}
using namespace MCMF;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, s, t; cin >> n >> m >> s >> t;
    init(n);
    for(int i = 1, u, v, w, c; i <= m; i++) {
        cin >> u >> v >> w >> c;
        add(u, v, w, c);
    }
    auto [a, b] = work(s, t);
    cout << a << " " << b << '\n';

    return 0;
}