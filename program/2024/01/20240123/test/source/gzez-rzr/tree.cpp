#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
const int N = 2e5 + 10;
struct edge {
    int to, w, nxt;
} e[N << 1];
int head[N], ecnt;
void addedge(int u, int v, int w) {
    e[++ecnt] = {v, w, head[u]};
    head[u] = ecnt;
}
bool vis[N];
ll dis[N];
int rt, siz[N], mx[N];
void getroot(int u, int tot) {
    siz[u] = 1;
    for(int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        getroot(v, tot);
        siz[u] += siz[v];
        mx[u] = max(mx[u], siz[v]);
    }
    mx[u] = max(mx[u], tot - siz[u]);
    if(!rt || mx[rt] > mx[u]) rt = u;
}
vector<int> vc[N];
void getdis(int u, int fa, int topf) {
    vc[topf].push_back(u);
    for(int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        if(v == fa) continue;
        dis[v] = dis[u] + e[i].w;
        getdis(v, u, topf);
        
    }
}
struct node {
    vector<int> vc;
    int sz;
    bool operator < (const node &x) const {
        return sz > x.sz;
    }
    friend node operator + (const node &x, const node &y) {
        node res;
        res.vc.clear();
        res.sz = x.sz + y.sz;
        for(auto u : x.vc) res.vc.push_back(u);
        for(auto u : y.vc) res.vc.push_back(u);
        return res;
    }
};
priority_queue<node> q;
int tot;
vector<pair<ll, int>> t[N];
void solve(int u) {
    getroot(u, 0);
    vector<int>().swap(vc[u]);
    vc[u].push_back(u);
    q.clear();
    q.push({vc[u], vc[u].size()});
    vis[u] = 1;
    dis[u] = 0;
    for(int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        vector<int>().swap(vc[v]);
        getdis(v, u, v);
        q.push({vc[v], vc[v].size()});
    }
    while(q.size() > 1) {
        node x = q.top();
        q.pop();
        node y = q.top();
        q.pop();
        ++tot;
        for(auto u : x.vc) t[tot].push_back({dis[u], u}), t[tot].push_back({-dis[u], -u});
        for(auto u : y.vc) t[tot].push_back({dis[u], u}), t[tot].push_back({-dis[u], -u});
        sort(t[tot].begin(), t[tot].end());
        q.push(x + y);
    }
    for(int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        if(vis[v]) continue;
        getroot(v, siz[v]);
        solve(rt);
    }
}
int main() {
    
    return 0;
}