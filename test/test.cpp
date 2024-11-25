#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using ll = long long ;
using VI = vector<ll>;

struct SCC {
    int n, idx, cnt;
    vector<VI> G;
    VI dfn, low, belong, stk;
    SCC(int _n) : n(_n), G(n + 1), dfn(n + 1), belong(n +1), low(n + 1) {
        idx = cnt = 0;
    }
    void add(int u, int v) {G[u].push_back(v); }
    ll dfs(int x) {
        low[x] = dfn[x] = ++idx;
        stk.push_back(x);
        for(auto to : G[x]) {
            if(!dfn[to]) low[x] = min(low[x], dfs(to));
            else if(!belong[to]) low[x] = min(low[x], dfn[to]);
        }
        if(low[x] == dfn[x]) {
            cnt++;
            for(int i = -1; i != x; stk.pop_back())
                belong[i = stk.back()] = cnt;
        }
        return low[x];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    VI A(n + 1); SCC S(n);
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v; i <= m; i++)   
        cin >> u >> v, S.add(u, v);
    rep(i, 1, n) if(!S.dfn[i]) S.dfs(i);
    rep(i, 1, n) cerr << S.belong[i] << " \n"[i == n];
    int cnt = S.cnt;
    vector<set<int>> G(cnt + 1);
    VI D(cnt + 1, -1), sum(cnt + 1);
    rep(i, 1, n) {
        int b = S.belong[i];
        sum[b] += A[i];
        for(auto to : S.G[i]) {
            int bt = S.belong[to];
            if(bt != b) G[b].insert(bt);
        }
    }
    ll ans = 0;
    function<ll(int)> dfs1 = [&](int x) {
        auto &d = D[x];
        if(d != -1) return d;
        d = sum[x];
        for(auto to : G[x]) d = max(d, sum[x] + dfs1(to));
        return d;
    };
    rep(i, 1, cnt) ans = max(ans, dfs1(i));
    cout << ans << '\n';
    return 0;
}