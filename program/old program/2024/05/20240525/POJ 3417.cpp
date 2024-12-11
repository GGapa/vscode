#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5;

struct Edge {
    int v, id;
};

vector<Edge> G[N];
int si[N], top[N], hson[N], fa[N], dep[N], ct[N], ans[N];
 
void dfs1(int x, int f) {
    si[x] = 1; dep[x] = dep[f] + 1; fa[x] = f;
    for(auto i : G[x]) {
        int to = i.v;
        if(to == f) continue;
        dfs1(to, x);
        ct[x] += ct[to];
        ans[i.id] = ct[to];
        si[x] += si[to];
        if(si[to] > si[hson[x]]) hson[x] = to;
    }
}
 
void dfs2(int x, int tp) {
    top[x] = tp;
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto i : G[x]) {
        int to = i.v;
        if(to == fa[x] || to == hson[x]) continue;
         dfs2(to, to);       
    }
}
 
int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);   
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 2, u, v; i <= n; i++) 
        cin >> u >> v, G[u].push_back({v, i}), G[v].push_back({u, i});
    dfs1(1, 0);
    dfs2(1, 0);
    for(int o = 1, x, y; o <= m; o++) {
        cin >> x >> y; 
        ct[x]++, ct[y]++;
        int l = lca(x, y);
        ct[l] -= 2;
    }
    dfs1(1, 0);
    int ret = 0;
    rep(i, 2, n) {
        if(!ans[i]) ret += m;
        if(ans[i] == 1) ret += 1;
    }
    cout << ret << '\n';
    return 0;
}