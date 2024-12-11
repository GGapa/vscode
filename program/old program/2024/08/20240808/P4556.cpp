#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct SegTree {
    static constexpr int N = 5000005 + 5;
    int sum[N], res[N], ls[N], rs[N];
    int n, cnt = 0;
    SegTree(int _n) {n = _n;}
    void update(int x) {
        if(sum[ls[x]] < sum[rs[x]]) {
            res[x] = res[rs[x]];
            sum[x] = sum[rs[x]];
        }
        else {
            res[x] = res[ls[x]];
            sum[x] = sum[ls[x]];
        }
    }
    int merge(int a, int b, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if(!a || !b) return max(a, b);
        if(l == r) {
            sum[a] += sum[b];
            return a;
        }    
        int mid = l + r >> 1;
        ls[a] = merge(ls[a], ls[b], l, mid);
        rs[a] = merge(rs[a], rs[b], mid + 1, r);
        update(a);
        return a;
    }
    int modify(int it, int val, int x, int l = 1, int r = -1)  {
        if(r == -1) r = n;
        if(!x) x = ++cnt;
        if(l == r) {
            sum[x] += val; res[x] = it;
            return x;
        }
        int mid = l + r >> 1;
        if(it <= mid) ls[x] = modify(it, val, ls[x], l, mid);
        else rs[x] = modify(it, val, rs[x], mid + 1, r);
        update(x);
        return x;
    }
}T(1e5);

constexpr int N = 1e5 + 5;

int fa[N][22], dep[N], rt[N], ans[N];
int n, m;
vector<int> G[N];

void dfs(int x) {
    rep(i, 0, 20) fa[x][i + 1] = fa[fa[x][i]][i];
    for(auto to : G[x]) if(to != fa[x][0]) {
        dep[to] = dep[x] + 1;
        fa[to][0] = x;
        dfs(to);
    }
}

int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int d = dep[x] - dep[y], i = 0; d; d >>= 1, i++)
        if(d & 1) x = fa[x][i];
    if(x == y) return x;
    per(i, 20, 0) 
        if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void calc(int x) {
    for(auto to : G[x]) if(to != fa[x][0]) {
        calc(to);
        rt[x] = T.merge(rt[x], rt[to]);
    }
    ans[x] = (T.sum[rt[x]] == 0 ? 0 : T.res[rt[x]]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs(1);
    for(int i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        rt[a] = T.modify(c, 1, rt[a]);
        rt[b] = T.modify(c, 1, rt[b]);
        int t = lca(a, b);
        rt[t] = T.modify(c, -1, rt[t]);
        t = fa[t][0];
        rt[t] = T.modify(c, -1, rt[t]);
    }
    calc(1);
    rep(i ,1, n) cout << ans[i] << "\n";
    return 0;
}