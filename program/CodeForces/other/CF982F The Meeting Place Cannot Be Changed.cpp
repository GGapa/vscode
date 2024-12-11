#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5;

int n, m; 
int vis[N], lim[N], dis[N], ans[N], nxt[N];
vector<int> G[N], cyc;
list<int> li;

void dfs(int x) {
    if(!cyc.empty() || lim[x]) return ;
    if(vis[x]) {
        if(vis[x] == 1) {
            while(li.size() && li.front() != x) li.pop_front();
            for(auto a : li) cyc.emplace_back(a);
        }
        return ;
    }
    li.emplace_back(x);
    vis[x] = 1;

    for(auto to : G[x]) if(!lim[to]) 
        dfs(to);
    if(li.size()) li.pop_back();

    vis[x] = 2;
}

void find() {
    memset(vis, 0, sizeof(vis));
    li.clear(); cyc.clear();
    rep(i, 1, n) if(!vis[i]) {
        if(cyc.size()) break;
        li.clear();
        dfs(i);
    }
}

int ret = -1;

int get(int rt, int x) {
    int ret = 0;
    rt = dis[rt]; x = dis[x];
    if(x > rt) ret = x - rt;
    else ret = m - rt + x;
    return ret;
}

void dfs1(int x, int rt, int cnt = 0) {
    if(dis[x] != -1 && cnt) {
        int t = x;
        if(ret == -1 || get(rt, x) > get(rt, ret)) ret = t;
        return;
    }
    if(vis[x]) return ;
    vis[x] = 1;

    for(auto to : G[x]) {
        if(to == nxt[x]) continue;
        dfs1(to, rt, 1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v);
        
    find();
    m = cyc.size();
    memset(dis, -1, sizeof(dis));
    rep(i, 0, m - 1) dis[cyc[i]] = i, nxt[cyc[i]] = cyc[(i + 1) % m];

    memset(vis, 0, sizeof(vis));
    rep(i, 0, m - 1) {
        ret = -1; dfs1(cyc[i], cyc[i]);
        int t = ret;
        if(t == -1) continue;
        t = dis[t];
        if(i < t) ans[i + 1]++, ans[t]--;
        else ans[(i + 1)]++, ans[m]--, ans[0]++, ans[t]--;
    }
    rep(i, 1, m - 1) ans[i] += ans[i - 1];
    int nw = -1;
    rep(i, 0, m - 1) if(ans[i] == 0) nw = i;
    if(nw == -1) return cout << nw << '\n', 0;
    nw = cyc[nw];

    memset(lim, 0, sizeof(lim));
    lim[nw] = 1;
    find();

    if(cyc.size()) return cout << -1 << '\n', 0;
    else cout << nw << '\n';
    return 0;
}