#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 2e5 + 5;
vector<int> G[N], d;
int n;

int pre[N];
int dis[N];
pair<int, int> F[N];

void dfs(int x, int fa) {
    dis[x] = dis[fa] + 1; pre[x] = fa;
    for(auto to : G[x]) if(to != fa) dfs(to, x);
}

void dp(int x, int fa) {
    set<pair<int, int>> s;
    s.insert({0, 0}); s.insert({0, 0}) ;
    for(auto to : G[x]) if(to != fa) {
        dp(to, x) ;
        s.insert({F[to].first, to}) ;
        s.insert({F[to].second, to}) ;
    }
    int t = s.rbegin()->second;
    F[x].first = s.rbegin()->first + 1;
    for(auto i = ++s.rbegin(); i != s.rend(); i++) if(i->second != t) {
        F[x].second = i->first + 1;
        break;
    }
}

void work() {
    fill(F, F + 1 + n, make_pair(0, 0)) ;
    fill(dis, dis + 1 + n, 0) ;
    dp(1, 0);
    dfs(1, 0);
    int it = 0;
    rep(i, 1, n) if(G[i].size() > 2 && (dis[i] > dis[it] || dis[i] == dis[it] && F[i].first + F[i].second > F[it].first + F[it].second)) it = i; 
    int l = it;
    fill(F, F + 1 + n, make_pair(0, 0)) ;
    fill(dis, dis + 1 + n, 0) ;
    dp(it, 0);
    dfs(it, 0) ; 
    it = 0;
    rep(i, 1, n) if(G[i].size() > 2 && (dis[i] > dis[it] || dis[i] == dis[it] && F[i].first + F[i].second > F[it].first + F[it].second)) it = i; 
    while(it != l) d.emplace_back(it), it = pre[it];
    d.emplace_back(l) ;
}

int vis[N];
void dfs2(int x) {
    vis[x] = 1;
    for(auto to : G[x]) if(!vis[to]) 
        pre[to] = x, dis[to] = dis[x] + 1, dfs2(to) ;
}

tuple<int, int> calc(int x) {
    fill(dis, dis + 1 + n, 0) ;
    fill(vis, vis + 1 + n, 0) ;
    for(auto a : d) vis[a] = 1;
    dfs2(x);
    int mx1, mx2; mx1 = mx2 = 0;
    rep(i, 1, n) if(dis[mx1] < dis[i]) mx1 = i;

    for(int t = mx1; t != x; t = pre[t]) dis[t] = -1; dis[mx1] = -1; 
    rep(i, 1, n) if(dis[mx2] <= dis[i] && i != mx1) mx2 = i;
    return {mx1, mx2} ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 2, u, v; i <= n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u) ;

    work() ;
    int m = d.size() ;
    int l = d[0], r = d[m - 1];
    int a1, a2, b1, b2;
    tie(a1, a2) = calc(l) ;
    tie(b1, b2) = calc(r) ;
    cout << a1 << " " << b1 << "\n" << a2 << " " << b2 << '\n';
    return 0;
}
