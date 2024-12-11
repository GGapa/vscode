#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct BIT {
    int n;
    vector<LL> T;
    BIT(int _n) : n(_n + 1) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(++x; x <= n; x += lowbit(x)) (T[x] += v);
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(++x; x > 0; x -= lowbit(x)) (res += T[x]);
        return res;
    }
    LL query(int l, int r) {
        if(l > r) return 0;
        return ask(r) - ask(l - 1); 
    }
    void clear() {fill(T.begin(), T.end(), 0); }
};
struct Node { int mn, mx, id, ty; };

const int N = 1e5 + 5, INF = 1e9 + 7;

vector<int> G[N];
vector<Node> par[N], son[N];
int si[N], mx[N], vis[N], c[N];
int rt = 0;

void grt(int x, int fa, int sum) {
    si[x] = 1, mx[x] = 0;
    for(auto to : G[x]) if(to != fa && !vis[to]) {
        grt(to, x, sum) ;
        si[x] += si[to]; mx[x] = max(mx[x], si[to]);
    }
    mx[x] = max(mx[x], sum - mx[x]) ;
    if(mx[x] < mx[rt]) rt = x;
}

void dfs(int x, int fa, int mn = INF, int mx = -INF) {
    mn = min(mn, x); mx = max(mx, x);
    par[x].push_back({mn, mx, rt}); son[rt].push_back({mn, mx, c[x], 0}) ;
    si[x] = 1;
    for(auto to : G[x]) if(to != fa && !vis[to]) 
        dfs(to, x, mn, mx), si[x] += si[to] ;
}

void work(int x) {
    vis[x] = 1; dfs(x, 0) ;
    for(auto to : G[x]) if(!vis[to]) {
        rt = 0, grt(to, 0, si[to]);
        work(rt);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> c[i] ;
    for(int i = 1, u, v; i < n; i++)    
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    mx[0] = n + 1; 
    rt = 0; grt(1, 0, n);
    work(rt); 
    for(int i = 1, l, r, x; i <= m; i++) {
        cin >> l >> r >> x;
        for(auto p : par[x]) if(l <= p.mn && p.mx <= r) {
            son[p.id].push_back({l, r, i, 1}); 
            break;
        }
    }
    vector<int> mx(n + 1, INF), ans(m + 1);
    BIT tr(n) ;
    rep(i, 1, n) {
        auto &a = son[i];
        vector<int> tmp;
        sort(a.begin(), a.end(), [&](const Node &x, const Node &y) {
            return x.mn > y.mn || x.mn == y.mn && x.ty < y.ty;
        });
        for(auto p : a) {
            if(p.ty) ans[p.id] = tr.ask(p.mx); 
            else if(p.mx < mx[p.id]) {
                if(mx[p.id] < INF) tr.add(mx[p.id], -1);
                tr.add(mx[p.id] = p.mx, 1);
            }
        }
        for(auto p : a) if(!p.ty && mx[p.id] < INF) tr.add(mx[p.id], -1), mx[p.id] = INF;
    }
    rep(i, 1, m) cout << ans[i] << '\n';
    return 0;
}
