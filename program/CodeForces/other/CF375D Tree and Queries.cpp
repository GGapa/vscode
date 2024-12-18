#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5;
vector<int> G[N];

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(; x && x <= n; x += lowbit(x)) T[x] += v;
    }
    ll ask(int x) {
        ll res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

BIT T(N);

int n, m;
int c[N];
int hson[N], si[N], in[N], out[N], nd[N];

void dfs1(int x, int fa) {
    in[x] = ++in[0]; si[x] = 1;
    nd[in[0]] = x;
    for(auto to : G[x]) if(to != fa) {
        dfs1(to, x);
        si[x] += si[to];
        if(si[hson[x]] < si[to]) hson[x] = to;
    }
    out[x] = in[0];
}

int ans[N], cnt[N], tot = 0;
vector<array<int, 2>> q[N];

void update(int u, int v) {
    u = c[u];
    T.add(cnt[u], -1);
    cnt[u] += v;
    T.add(cnt[u], 1);
    // rep(i ,1, n) cout << cnt[i] << " \n"[i == n];
}

void getans(int x) {
    // rep(i, 1, n) cout << cnt[i] << " \n"[i == n];
    for(auto p : q[x]) ans[p[1]] = T.ask(1e5) - T.ask(p[0]);
}

void dfs2(int x, int fa, bool tag) {
    for(auto to : G[x]) if(to != fa && to != hson[x]) 
        dfs2(to, x, 0);
    if(hson[x]) dfs2(hson[x], x, 1);    
    update(x, 1);
    for(auto to : G[x]) if(to != hson[x] && to != fa) 
        rep(i, in[to], out[to]) update(nd[i], 1);
    getans(x);
    if(!tag) rep(i, in[x], out[x]) update(nd[i], -1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(cnt, cnt + N, 1);
    T.add(1, n);
    rep(i ,1, n) cin >> c[i];
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    for(int u, c, i  =1; i <= m; i++) {
        cin >> u >> c;
        q[u].push_back({c, i});
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    rep(i ,1, m) cout << ans[i] << '\n';
    return 0;
}