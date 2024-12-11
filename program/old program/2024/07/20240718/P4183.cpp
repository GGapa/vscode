#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

bool debug = 1;
const int N = 1e5 + 5;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    ll ask(int x) {
        ll res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};
BIT T(N * 2);

int n;
vector<int> G[N];
int mx[N], si[N], vis[N];
int deg[N], mn[N], dis[N], ans[N];
int rt = 0;

void groot(int x, int fa, int sum) {
    si[x] = 1; mx[x]  = 0;
    for(auto to : G[x]) if(to != fa && !vis[to]) {
        groot(to, x, sum) ;
        si[x] += si[to];
        mx[x] = max(mx[x], si[to]);
    }
    mx[x] = max(mx[x], sum - si[x]);
    if(mx[x] < mx[rt]) rt = x;
} 

vector<int> A;

void gdis(int x, int fa) {
    A.emplace_back(x);
    for(auto to : G[x]) if(to != fa && !vis[to]) {
        dis[to] = dis[x] + 1;
        gdis(to, x);
    }
}

void calc(int x, int v, int ty) {
    A.clear(); dis[x] = v;
    gdis(x, 0);
    // if(debug) rep(i, 1, n) cout << dis[i] << " \n"[i == n];
    for(auto a : A) T.add(mn[a] - dis[a] + n, 2 - deg[a]);
    for(auto a : A) ans[a] += ty * T.ask(dis[a] + n);
    for(auto a : A) T.add(mn[a] - dis[a] + n, deg[a] - 2);
}

void dfs(int x, int fa) {
    calc(x, 0, 1) ;   
    vis[x] = 1;
    for(auto to : G[x]) if(to != fa && !vis[to]) {
        calc(to, 1, -1);
        rt = 0;
        groot(to, rt, si[to]);
        dfs(rt, x);
    }
}

void gmn1(int x, int fa) {
    mn[x] = n + 1;
    if(G[x].size() == 1) {
        mn[x] = 0;
        if(fa) return ;
    }
    for(auto to : G[x]) if(to != fa) {
        gmn1(to, x);
        mn[x] = min(mn[x], mn[to] + 1);
    }
}

void gmn2(int x, int fa) { 
    for(auto to : G[x]) if(to != fa) {
        mn[to] = min(mn[to], mn[x] + 1);
        gmn2(to, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u), deg[u]++, deg[v]++;
    gmn1(1, 0); 
    // if(debug) rep(i, 1, n) cout << mn[i] << " \n"[i == n];
    gmn2(1, 0);
    rt = 0; mx[rt] = n + 1;
    groot(1, 0, n); 
    dfs(rt, 0);
    rep(i, 1, n) cout << (deg[i] == 1 ? 1 : ans[i]) << '\n';
    return 0;
}
