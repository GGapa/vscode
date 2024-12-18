// Electricity 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct EBCC {
    int n, idx;
    vector<VI> G;
    VI dfn, low, cnt;
    EBCC(int _n) : n(_n), dfn(_n + 1), low(_n + 1), G(_n + 1), cnt(_n + 1) {
        idx = 0;
    }
    void add(int u, int v) {
        G[u].push_back(v), G[v].push_back(u);
    }
    int dfs(int x, int p) {
        low[x] = dfn[x] = ++idx;
        for(auto to : G[x]) if(to != p) {
            if(!dfn[to]) {
                int t = dfs(to, x);
                low[x] = min(low[x], t);
                if(t >= dfn[x]) 
                    cnt[x]++;
            }
            else 
                low[x] = min(low[x], dfn[to]);
        }
        cnt[x] -= (p == -1);
        return low[x];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n, m; cin >> n >> m  && n; ) {
        EBCC tj(n);
        for(int i = 1, u, v; i <= m; i++) 
            cin >> u >> v, tj.add(++u, ++v);
        int cc = 0;
        rep(i, 1, n) if(!tj.dfn[i]) tj.dfs(i, -1), cc++;
        cout << cc + *max_element(tj.cnt.begin() + 1, tj.cnt.end()) << '\n';
    }
    return 0;
}