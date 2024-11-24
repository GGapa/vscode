#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 3e5 + 5;

int c[N], F[N], si[N],G[N];
vector<int> gr[N];

void dfs(int x, int fa) {
    if(c[x] == 1) F[x] = 1;
    si[x] = c[x];
    for(auto to : gr[x]) if(to != fa) {
        dfs(to, x);
        si[x] += si[to];
        if(si[to] >= 2 && F[to])  F[x] = 1;
        if(c[to] == 1) F[x] = 1;
    }
}

void dfs1(int x, int fa) {
    if(c[fa] == 1) G[x] = 1;
    if(F[x] == 1) G[x] = 1;
    for(auto to : gr[x]) if(to != fa) {
        if(G[x] && si[1] - si[to] >= 2) G[to] = 1;
        dfs1(to, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;  
    rep(i ,1, n) cin >> c[i];
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, gr[u].push_back(v), gr[v].push_back(u);
    dfs(1, 0); dfs1(1, 0);
    rep(i, 1, n) cout << (F[i] || G[i]) << " \n"[i == n];
    return 0;
}