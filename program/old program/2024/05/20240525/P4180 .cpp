#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5, M = 3e5 + 5;
const int ML = 17;

struct Edge {
    int v, w;
};
vector<Edge> G[N];
int n, m;

array<int, 3> E[M];
int vis[M];
ll mns = 0;
namespace kruskal {
    vector<int> fa;
    int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
    bool merge(int x, int y) {
        // cout << x << " " << y << '\n';
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;
    }
    void work() {
        sort(E + 1, E + 1 + m);
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        int cnt = 1;
        rep(i, 1, m) {
            int x = E[i][1], y = E[i][2];
            if(merge(x, y)) mns += E[i][0], cnt++, G[x].push_back({y, E[i][0]}), G[y].push_back({x, E[i][0]});
            if(cnt == 0) break;
        }
    }
}

namespace T {
    using pi =  pair<int, int>;
    int F[N][20], dep[N];
    pi mx[N][20];
    pi merge(pi a, pi b) {
        if(b.first > a.first) swap(a, b);
        if(a.first == b.first) a.second = max(a.second, b.second);
        else a.second = max(a.second, b.first);
        return a;
    }
    void dfs(int x) {
        rep(i, 1, 17) F[x][i] = F[F[x][i - 1]][i - 1];
        rep(i, 1, 17) mx[x][i] = merge(mx[x][i - 1], mx[F[x][i - 1]][i - 1]);
        for(auto i : G[x])  {
            int to = i.v, w = i.w;
            if(to == F[x][0]) continue;
            F[to][0] = x, mx[to][0] = {w, -1}; dep[to] = dep[x] + 1;
            dfs(to);
        }
    }
    void work(int s) {
        dep[s] = 1, mx[s][0] = {-1, -1}; 
        dfs(s);
    }
    int LCA(int x, int y) {
        if(dep[x] < dep[y]) swap(x, y);
        int d = dep[x] - dep[y];
        rep(i, 0, 17) if((d >> i) & 1) x = F[x][i];
        if(x == y) return x;
        per(i, 17, 0) if(F[x][i] != F[y][i]) x = F[x][i], y = F[y][i];
        return F[x][0];
    }
    pi query(int x, int d) {
        pi ret = {-1, -1};
        rep(i, 0, 17) if((d >> i) & 1) ret = merge(ret, mx[x][i]), x = F[x][i];
        return ret;
    }
    pi ask(int x, int y) {
        int d = dep[LCA(x, y)];
        return merge(query(x, dep[x] - d), query(y, dep[y] - d));
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, E[i] = {w, u, v};
    kruskal::work();
    T::work(1);
    ll ret = LLONG_MAX;
    rep(i, 1, m)  {
        auto e = E[i];
        if(e[1] == e[2] || vis[i]) continue;
        auto p = T::ask(e[1], e[2]); 
        if(p.first == e[0]) {if(~p.second) ret = min(ret, mns + e[0] - p.second);}
        else if(~p.first) ret = min(ret, mns + e[0] - p.first);
    }
    cout << ret << '\n';
    return 0;
}