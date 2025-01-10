#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5;

int n, m;
int dep[N], fa[N];
vector<int> G[N];

namespace LCA {
    constexpr int B = __lg(N) + 1;

    int dfn[N], mn[B][N];
 
    void dfs(int x, int pa) {
        dfn[x] = ++dfn[N - 1]; mn[0][dfn[x]] = pa;
        dep[x] = dep[pa] + 1; fa[x] = pa;
        for(auto to : G[x]) if(to != pa) dfs(to, x);
    }
 
    int get(int x, int y) {return (dfn[x] < dfn[y] ? x : y); }
 
    void init(int rt) {   
        dfs(rt, 0);
        rep(i, 1, B - 1) for(int j = 1; j + (1 << i) - 1 <= n; j++) 
            mn[i][j] = get(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
    }
 
    int lca(int x, int y) {
        if(x == y) return x;
        if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
        int d = __lg(y - x++);
        return get(mn[d][x], mn[d][y - (1 << d) + 1]);
    }
}
using LCA::lca, LCA::dfn;

namespace SGT {
    int lss[N << 6], rss[N << 6], sum[N << 6], mx[N << 6], mn[N << 6], cnt[N << 6], rt[N << 6], idx = 0;
    
    #define ls lss[x]
    #define rs rss[x]

    void init() {idx = 0; }
    void pushup(int x) {
        if(x == 148358) cerr << sum[x] << " " << sum[ls] << " " << sum[rs] << " " << dep[lca(mx[ls], mn[rs])] << '\n';
        sum[x] = sum[ls] + sum[rs] - dep[lca(mx[ls], mn[rs])];
        if(x == 148358) cerr << sum[x] << " " << sum[ls] << " " << sum[rs] << " " << dep[lca(mx[ls], mn[rs])] << '\n';
        mn[x] = mn[ls] ? mn[ls] : mn[rs];
        mx[x] = mx[rs] ? mx[rs] : mx[ls];
    }   // cnt 是对于每个节点单独记录的，所以不用 pushup
    void modify(int it, int v, int &x, int l = 1, int r = n) {
        if(!x) x = ++idx;
        if(l == r) {
            cnt[x] += v;
            mn[x] = mx[x] = (cnt[x] ? it : 0);
            sum[x] = (cnt[x] ? dep[it] : 0);
            return ;
        }
        int mid = l + r >> 1;
        if(dfn[it] <= mid) modify(it, v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        pushup(x);
    }
    void merge(int &x, int y, int l = 1, int r = n) {
        if(x == 0 || y == 0) return x = max(x, y) ,void();
        if(l == r) {
            cnt[x] += cnt[y];
            mn[x] = max(mn[x], mn[y]);
            mx[x] = max(mx[x], mx[y]);
            sum[x] = max(sum[x], sum[y]);
            return ;
        }
        int mid = l + r >> 1;
        merge(ls, lss[y], l, mid);
        merge(rs, rss[y], mid + 1, r);
        if(x == 148358) cerr << sum[x] << " " << l << " " << r << '\n';
        pushup(x);
    } 
    int query(int x) {return sum[x] - dep[lca(mn[x], mx[x])]; }

    #undef ls
    #undef rs
}

vector<int> op[N];
LL ans = 0;

void dfs(int x) {
    for(auto to : G[x]) if(to != fa[x]) dfs(to);
    for(auto i : op[x]) SGT::modify(i, -1, SGT::rt[x]);
    ans += SGT::query(SGT::rt[x]); 
    SGT::merge(SGT::rt[fa[x]], SGT::rt[x]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    LCA::init(1);
    cerr << "INIT success!" << '\n';
    for(int i = 1, s, t; i <= m; i++) {
        cin >> s >> t;
        int lc = lca(s, t);
        SGT::modify(s, 1, SGT::rt[s]); SGT::modify(t, 1, SGT::rt[s]);
        SGT::modify(s, 1, SGT::rt[t]); SGT::modify(t, 1, SGT::rt[t]);
        op[lc].emplace_back(s), op[fa[lc]].emplace_back(s);
        op[lc].emplace_back(t), op[fa[lc]].emplace_back(t);
    }
    cerr << "INPUT success!\n";
    dfs(1);
    cout << ans / 2 << '\n';
    return 0;
}
/*
g++ P5327.cpp -o run && ./run
164352
*/