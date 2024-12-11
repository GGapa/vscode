#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
int n, m; 

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
                low[x] = min(low[x], low[to]);
        }
        if(low[x] == dfn[x]) {
            cnt++;
            for(int i = -1; i != x; stk.pop_back()) 
                i = stk.back(), belong[i] = cnt;
        }
        return low[x];

    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    SCC S(n);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, S.add(u, v);
    rep(i, 1, n) if(!S.dfn[i]) S.dfs(i);
    cout << S.cnt << '\n';
    rep(i, 1, n) cout << S.cnt - S.belong[i] + 1 << ' ';
    return 0;
}