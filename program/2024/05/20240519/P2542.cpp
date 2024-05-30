#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;

#define lson(o) (o << 1)
#define rson(o) (o << 1 | 1)
const int MN = 1e5 + 5;

int w[MN], val[MN], dfn[MN], sz[MN], fa[MN], top[MN], hson[MN], dep[MN];
vector<int> G[MN];

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + (c & 15); c = getchar(); }
    return x * f;
}

int dfs1(int u, int d) {
    dep[u] = d, sz[u] = 1, hson[u] = 0;
    for (int to : G[u]) {
        if (to == fa[u]) continue;
        fa[to] = u;
        sz[u] += dfs1(to, d + 1);
        if (sz[to] > sz[hson[u]]) hson[u] = to;
    }
    return sz[u];
}

int tot = 0;
void dfs2(int u, int tp) {
    dfn[u] = ++tot, top[u] = tp, val[dfn[u]] = w[u];
    if (hson[u]) dfs2(hson[u], tp);
    for (int to : G[u]) {
        if (to == fa[u] || to == hson[u]) continue;
        dfs2(to, to);
    }
}

struct SegTree {
    int d[MN << 2], L[MN << 2], R[MN << 2], lz[MN << 2];

    inline void pushup(int o) {
        d[o] = d[lson(o)] + d[rson(o)] + (L[rson(o)] == R[lson(o)]);
        L[o] = L[lson(o)], R[o] = R[rson(o)];
    }

    inline void build(int l, int r, int o) {
        lz[o] = 0;
        if (l == r) {
            d[o] = 0;
            L[o] = R[o] = val[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson(o));
        build(mid + 1, r, rson(o));
        pushup(o);
    }

    inline void pushdown(int ql, int qr, int o) {
        if (!lz[o]) return;
        int mid = (ql + qr) >> 1;
        d[lson(o)] = mid - ql;
        d[rson(o)] = qr - mid - 1;
        lz[lson(o)] = lz[o];
        lz[rson(o)] = lz[o];
        L[lson(o)] = R[lson(o)] = L[rson(o)] = R[rson(o)] = lz[o];
        lz[o] = 0;
    }

    inline int query(int l, int r, int ql, int qr, int o) {
        if (l <= ql && qr <= r) return d[o];
        pushdown(ql, qr, o);
        int mid = (ql + qr) >> 1, ans = 0;
        if (l <= mid) ans += query(l, r, ql, mid, lson(o));
        if (r > mid) ans += query(l, r, mid + 1, qr, rson(o));
        if (l <= mid && r > mid && R[lson(o)] == L[rson(o)]) ans++;
        return ans;
    }

    inline void modify(int l, int r, int k, int ql, int qr, int o) {
        if (l <= ql && qr <= r) {
            L[o] = R[o] = lz[o] = k;
            d[o] = qr - ql;
            return;
        }
        pushdown(ql, qr, o);
        int mid = (ql + qr) >> 1;
        if (l <= mid) modify(l, r, k, ql, mid, lson(o));
        if (r > mid) modify(l, r, k, mid + 1, qr, rson(o));
        pushup(o);
    }

    inline int kwii(int pos, int ql, int qr, int o) {
        if (ql == qr) return L[o];
        pushdown(ql, qr, o);
        int mid = (ql + qr) >> 1;
        if (pos <= mid) return kwii(pos, ql, mid, lson(o));
        else return kwii(pos, mid + 1, qr, rson(o));
    }
};

SegTree tree;
int n, m;

int cnt = 0;
void change(int x, int y) {
    ++cnt;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        tree.modify(dfn[top[x]], dfn[x], cnt, 1, n, 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    tree.modify(dfn[x], dfn[y], cnt, 1, n, 1);
}

int queryans(int x, int y) {
    int res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res += tree.query(dfn[top[x]], dfn[x], 1, n, 1);
        if (tree.kwii(dfn[fa[top[x]]], 1, n, 1) == tree.kwii(dfn[top[x]], 1, n, 1)) res++;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    res += tree.query(dfn[x], dfn[y], 1, n, 1);
    return res;
}

void solve() {
    cnt = tot = 0;
    n = read(), m = read();
    rep(i, 1, n) w[i] = ++cnt;

    rep(i, 1, n - 1) {
        int u = read(), v = read();
        G[u].push_back(v), G[v].push_back(u);
    }

    dfs1(1, 1);
    dfs2(1, 1);

    tree.build(1, n, 1);

    while (m--) {
        int op = read(), x = read(), y = read();
        if (op == 1) change(x, y);
        if (op == 2) cout << queryans(x, y) << '\n';
    }

    rep(i, 1, n) G[i].clear();
}

int _;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> _;
    while (_--) solve();

    return 0;
}
