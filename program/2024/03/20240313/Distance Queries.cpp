// Distance Queries
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int si[N], f[N], hs[N], top[N], dep[N];

vector<int> G[N];

void dfs1(int x, int fa) {
    si[x] = 1; f[x] = fa; dep[x] = dep[fa] + 1;
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs1(to, x);
        si[x] += si[to];
        if(si[hs[x]] < si[to]) hs[x] = to;
    }
}

void dfs2(int x, int tp) {
    top[x] = tp;
    if(hs[x]) dfs2(hs[x], tp);
    for(auto to : G[x]) {
        if(to == f[x] || to == hs[x]) continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = f[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for(int i = 1, u, v; i <= q; i++) {
        cin >> u >> v;
        int L = LCA(u, v);
        cout << abs(2 * dep[L] - dep[u] - dep[v]) << '\n';
    }
    return 0;
}