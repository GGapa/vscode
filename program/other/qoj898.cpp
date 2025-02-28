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

namespace MF {
    struct E {
        int v; LL w;
        E(int v = 0, LL w = 0) : v(v), w(w) {}
    };
    vector<E> e;
    vector<int> G[N];
    void addE(int u, int v, LL w) {
        G[u].emplace_back(e.size());
        e.emplace_back(v, w);
    }
    int add(int u, int v, LL w) {
        addE(u, v, w); addE(v, u, 0);
        return (int)e.size() - 2;
    }

    int n = -1;
    int dep[N], cur[N];
    void init(int nn) {n = nn; }
    bool bfs(int s, int t) {
        fill(dep, dep + 1 + n, 0);
        queue<int> q;
        dep[s] = 1; q.push(s);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(auto i : G[x]) {
                auto [to, w] = e[i];
                if(!dep[to] && w) {
                    dep[to] = dep[x] + 1;
                    q.emplace(to);
                }
            }
        }
        return dep[t];
    }
    LL dfs(int x, int t, LL in) {
        if(x == t) return in;
        LL out = 0;
        for(int &i = cur[x]; i < G[x].size(); i++) {
            int id = G[x][i];
            auto [to, w] = e[id];
            if(dep[to] == dep[x] + 1 && w) {
                LL f = dfs(to, t, min(in - out, w));
                out += f;
                e[id].w -= f; e[id ^ 1].w += f;
                if(out == in) return out;
            } 
        }
        if(!out) dep[x] = 0;
        return out;
    }
    LL work(int s, int t) {
        assert(n != -1);
        LL ret = 0;
        while(bfs(s, t)) {
            fill(cur, cur + 1 + n, 0);
            ret += dfs(s, t, 1e18);
        }
        return ret;
    }
}
using namespace MF;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int L, R, m; cin >> L >> R >> m;
    int n = L + R;
    int S = n + 1, T = n + 2;
    init(T);
    rep(i, 1, L) add(S, i, 1);
    rep(i, 1, R) add(i + L, T, 1);
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        v += L; 
        u++; v++;
        add(u, v, 1);
    }
    work(S, T);
    vector<AI<2>> ans;
    rep(x, 1, L) {
        for(auto i : G[x]) {
            auto [to, w] = e[i];
            if(w == 0 && L + 1 <= to && to <= n) ans.push_back({x, to});
        }
    }
    cout << ans.size() << '\n';
    for(auto [a, b] : ans) cout << a - 1 << " " << b - L - 1<< '\n';

    return 0;
}