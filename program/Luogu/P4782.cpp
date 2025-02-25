#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct SCC {
    int n, idx, cnt;
    vector<VI> G;
    VI stk, dfn, low, belong;
    SCC(int _n) : n(_n), G(n + 1), low(n + 1), belong(n + 1), dfn(n + 1) {
        idx = cnt = 0;
    }   
    void add(int u, int v) {G[u].push_back(v); };
    int dfs(int x) {
        low[x] = dfn[x] = ++idx;
        stk.push_back(x);
        for(auto to : G[x]) {
            if(!dfn[to]) 
                low[x] = min(low[x], dfs(to));
            else if(!belong[to])
                low[x] = min(low[x], dfn[to]);
        }
        if(low[x] == dfn[x]) {
            cnt++;
            for(int i = -1; i != x; stk.pop_back()) 
                i = stk.back(), belong[i] = cnt;
        }
        return low[x];
    }
    void work() {
        rep(i, 1, n) if(!dfn[i]) dfs(i);
        int m = n / 2;
        rep(i, 1, m) if(belong[i] == belong[i + m]) return cout << "POSSIBLE\n", void();
        cout << "IMPOSSIBLE\n";
        rep(i, 1, m) cout << (belong[i] < belong[i + m]) << " \n"[i == m];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    SCC tj(n * 2);
    for(int i = 1, u, a, v, b; i <= m; i++) {
        cin >> u >> a >> v >> b;
        tj.add(u + n * (a & 1), v + n * (b ^ 1));
        tj.add(v + n * (b & 1), u + n * (a ^ 1));
    }
    tj.work();
    return 0;
}
/*
3 1
1 0 3 0
*/