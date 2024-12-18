#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


struct SegTree {
    int n, tot = 0;
    static constexpr int INF = 2e9;
    struct Node {
        int mn = INF, l, r; 
    };
    vector<Node> T;
    SegTree(int _n) : n(_n), T(_n << 6)  {} 
    int lc(int x) {return T[x].l; }
    int rc(int x) {return T[x].r; }
    int modify(int v, int it, int lt, int l = 1, int r = -1) {
        if(r == -1) r = n;
        int x = ++tot, mid = l + r >> 1;
        T[x] = T[lt] ;  
        if(l == r) return T[x].mn = v, x;
        if(it <= mid) T[x].l = modify(v, it, T[lt].l, l, mid);
        else T[x].r = modify(v, it, T[lt].r, mid + 1, r) ;
        T[x].mn = min(T[lc(x)].mn, T[rc(x)].mn) ;
        return x;
    }
    int query(int x, int L, int R, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) return T[x].mn;
        int mid = l + r >> 1, ret = INF;
        if(L <= mid) ret = min(ret, query(lc(x), L, R, l, mid)) ;
        if(mid < R) ret = min(ret, query(rc(x), L, R, mid + 1, r)) ;
        return ret;
    }
};
const int N = 1e5 + 5;
int dfn[N], si[N], dep[N];
vector<int> G[N];

void dfs(int x, int fa) {
    si[x] = 1; dfn[x] = ++dfn[0]; dep[x] = dep[fa] + 1;
    for(auto to : G[x]) if(to != fa) 
        dfs(to, x), si[x] += si[to];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, r; cin >> n >> r;
    vector<int> rt(n + 1), A(n + 1);
    rep(i ,1, n) cin >> A[i];
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u) ;
    dfs(r, 0) ;
    vector<int> id(n + 1) ;
    iota(id.begin(), id.end(), 0) ;
    sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
        return dep[x] < dep[y]  ;
    });
    SegTree T(n) ;
    rep(c, 1, n)  {
        int i = id[c] ;
        rt[dep[i]] = T.modify(A[i], dfn[i], rt[dep[id[c - 1]]]) ;
    }
    int q; cin >> q;
    int ans = 0;
    while(q--) {
        int x, k; cin >> x >> k;
        x = (x + ans) % n + 1; k = (k + ans) % n;
        cout << (ans = T.query(rt[min(dep[x] + k, dep[id[n]])], dfn[x], dfn[x] + si[x] - 1)) << '\n';
    }
    return 0;
}