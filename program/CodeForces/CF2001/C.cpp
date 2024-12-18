#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1000 + 5;

int fa[N], vis[N];
vector<int> G[N];

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int ret; cin >> ret;
    return ret;
}

void dfs(int u, int v) {    // u 的深度小于 v
    vis[u] = vis[v] = 1;
    if(u == v) return ; 
    int x = ask(u, v) ;
    if(x == u || x == v) {
        G[u].emplace_back(v);
        return ;
    }
    else if(vis[x]) {
        dfs(x, v);
    }
    else {
        dfs(u, x); dfs(x, v);
    }
}

void out(int x, int fa) {
    for(auto to : G[x]) if(to != fa) 
        cout << x << " " << to << " ", out(to, x) ;
} 

void solve() {
    int n; cin >> n;
    rep(i, 1, n) G[i].clear();
    fill(fa, fa + 1 + n, 0); fill(vis, vis + 1 + n, 0) ;
    vis[1] = 1;
    rep(i, 2, n) if(!vis[i]) dfs(1, i);
    cout << "! ";
    out(1, 0);
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
