#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct Mat {
    int n; 
    int A[2][2];
    int* operator [](int i)  {return A[i];} 
    const int* operator [](int i) const { return A[i]; } //在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。
    Mat() : n(1) { A[0][0] = A[0][1] = A[1][0] = A[1][1] = -1e9; }
    const Mat operator*(const Mat &B) const {
        Mat C; 
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] = max(C[i][j], A[i][k] + B[k][j]));
        return C;
    }
};

constexpr int N = 1e5 + 5, INF = 1e9;

vector<int> G[N];
int hson[N], top[N], siz[N], fa[N], dfn[N], w[N], out[N], id[N];
int F[N][2], g[N][2];
Mat val[N];

#define ls (x << 1)
#define rs ((x << 1) | 1)
namespace SGT {
    int n;
    Mat tr[N << 2];
    void pushup(int x) { tr[x] = tr[ls] * tr[rs]; }
    void build(int x =  1, int l = 1, int r = n) {
        if(l == r) {
            int t = id[l];
            tr[x][0][0] = tr[x][0][1] = g[t][0];
            tr[x][1][0] = g[t][1], tr[x][1][1] = -INF;
            val[l] = tr[x];
            return ;
        }
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void init(int nn) {n = nn, build(); }
    Mat query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x];
        int mid = l + r >> 1;
        if(L <= mid && mid < R) return query(L, R, ls, l, mid) * query(L, R, rs, mid + 1, r);
        if(L <= mid) return query(L, R, ls, l, mid);
        if(mid < R)return query(L, R, rs, mid + 1, r);
        assert(false);
        return {};
    }
    void modify(int it, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = val[it], void();
        int mid = l + r >> 1;
        if(it <= mid) modify(it, ls, l, mid);
        else modify(it, rs, mid + 1, r);
        pushup(x);
    } 
}
#undef ls
#undef rs

void modify(int it, int v) {
    int x = dfn[it];
    val[x][1][0] += v - w[it];
    w[it] = v;
    Mat od, nw;
    while(it) {
        od = SGT::query(dfn[top[it]], out[top[it]]);
        SGT::modify(x);
        nw = SGT::query(dfn[top[it]], out[top[it]]);
        it = fa[top[it]];
        x = dfn[it];
        val[x][0][1] = (val[x][0][0] += max(nw[0][0], nw[1][0]) - max(od[0][0], od[1][0]));
        val[x][1][0] += nw[0][0] - od[0][0];
    }
}

void dfs(int x, int pa) {
    fa[x] = pa; siz[x] = 1; 
    for(auto to : G[x]) if(to != pa) {
        dfs(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[hson[x]]) hson[x] = to;
    }
}

void dfs1(int x, int tp) {
    g[x][1] += w[x];
    for(auto to : G[x]) if(to != fa[x] && to != hson[x]) {
        dfs1(to, to);
        g[x][0] += max(F[to][0], F[to][1]);
        g[x][1] += F[to][0];
    }
    if(hson[x]) {
        int to = hson[x];
        dfs1(hson[x], tp);
        F[x][0] = g[x][0] + max(F[to][0], F[to][1]);
        F[x][1] = g[x][1] + F[to][0];
    }
    else F[x][0] = g[x][0], F[x][1] = g[x][1]; 
}   // 重剖 + 处理 F 和 G

void dfs2(int x, int tp) {
    dfn[x] = ++dfn[N - 1]; top[x] = tp; out[tp] = dfn[x]; id[dfn[x]] = x;   // 这里有一个坏习惯，不应当使用 dfn[0] 作为计数器，有时候 dfn[0] 也会被访问到，但是 dfn[N - 1] 访问到的概率要小一些 
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto to : G[x]) if(to != fa[x] && to != hson[x]) 
        dfs2(to, to);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n;
    rep(i, 1, n) cin >> w[i];
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    cin >> q;
    dfs(1, 0); 
    dfs2(1, 1);
    dfs1(1, 0);
    SGT::init(n);

    for(int x, y; q--; ) {
        cin >> x >> y;
        modify(x, y);
        Mat ans = SGT::query(dfn[1], out[top[1]]);
        cout << max(ans[0][0], ans[1][0]) << '\n';
    }
    return 0;
}
/*

*/

