#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 5e5 + 5;

int n, q;
int dep[N], A[N];
vector<int> G[N];

using AI = array<int, 5>;
vector<AI> itv;

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    int tr[N << 2];

    void clear() {
        fill_n(tr, N << 2, 0);
    }

    void apply(int x, int v) { tr[x] = max(tr[x],  v);}
    void pushup(int x) { tr[x] = max(tr[ls], tr[rs]);}

    void modify(int it, int v, int x = 1, int l = 1, int r = n) {
        if(l == r) return apply(x, v);
        int mid = l + r >> 1;
        if(it <= mid) modify(it,  v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        pushup(x);
    }

    int query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x];
        int mid = l + r >> 1, ret = 0;
        if(L <= mid) ret = max(ret, query(L, R, ls, l, mid));
        if(mid < R) ret = max(ret, query(L, R, rs, mid + 1, r));
        return ret;
    }
}
#undef ls
#undef rs
 
namespace LCA {
    constexpr int B = 20;
    int dfn[N], mn[B][N], L[N], R[N];
 
    void dfs(int x, int pa) {
        dfn[x] = ++dfn[N - 1]; mn[0][dfn[x]] = pa;
        dep[x] = dep[pa] + 1;
        for(auto to : G[x]) if(to != pa) dfs(to, x);
    }
 
    int get(int x, int y) {return (dfn[x] < dfn[y] ? x : y); }
 
    int lca(int x, int y) {
        if(x == y) return x;
        if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
        int d = __lg(y - x++);
        return get(mn[d][x], mn[d][y - (1 << d) + 1]);
    }

    void init(int rt) {   
        dfs(rt, 0);
        rep(i, 1, B - 1) for(int j = 1; j + (1 << i) - 1 <= n; j++) 
            mn[i][j] = get(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);

        vector<int> stk(1);
        rep(i, 1, n - 1) {
            A[i] = dep[lca(i, i + 1)];
            while(A[stk.back()] > A[i]) R[stk.back()] = i - 1, stk.pop_back();
            L[i] = stk.back() + 1;
            stk.emplace_back(i);
        }
        for(auto i : stk) R[i] = n;

        rep(i, 1, n - 1) itv.push_back({L[i], R[i], R[i] - L[i] + 1, A[i]});

        rep(i, 1, n) SGT::modify(i, dep[i]);
    }
}
using LCA::lca;

int ans[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    LCA::init(1);

    cin >> q;
    for(int l, r, k, i = 1; i <= q; i++) {
        cin >> l >> r >> k;
        if(k == 1) ans[i] = SGT::query(l, r);
        else itv.push_back({l, r - 1, k - 1, i, 1});   // 注意这里的右端点和 k 均 -1
    }

    SGT::clear();

    sort(itv.begin(), itv.end(), [&](const AI &x, const AI &y) {
        return (x[2] != y[2] ? x[2] > y[2] : x[4] < y[4]);
    });

    for(auto p : itv) {
        if(p[4]) {
            ans[p[3]] = max(ans[p[3]], SGT::query(p[0], p[1] - p[2] + 1));
        }
        else {
            SGT::modify(p[0], p[3]);
        }
    }

    sort(itv.begin(), itv.end(), [&](const AI &x, const AI &y) {
        return (x[0] != y[0] ? x[0] < y[0] : x[4] < y[4]);
    });

    SGT::clear();
    for(auto p : itv) {
        if(p[4]) {
            ans[p[3]] = max(ans[p[3]], SGT::query(p[0] + p[2] - 1, n - 1));
        }
        else {
            SGT::modify(p[1], p[3]);
        }
    }

    SGT::clear();
    sort(itv.begin(), itv.end(), [&](const AI &x, const AI &y) {
        return (x[1] != y[1] ? x[1] > y[1] : x[4] < y[4]);
    });

    for(auto p : itv) {
        if(p[4]) 
            ans[p[3]] = max(ans[p[3]], SGT::query(1, p[1] - p[2] + 1));
        else
            SGT::modify(p[0], p[3]);
    }

    rep(i, 1, q) cout << ans[i] << '\n';
    return 0;
}