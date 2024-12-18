#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;


// int n, head[N], cnt;
// struct node
// {
//     int v, w, nxt;
// } e[N];
vector<int> G[N];
// void Add_edge(int u, int v, int w)
// {
//     e[++cnt] = (node){v, w, head[u]};
//     head[u] = cnt;
// }

int d1[N], d2[N], c1[N], c2[N]; 
void dfs1(int u, int fa) {
    for(auto v : G[u]) {
        if (v == fa)
            continue;
        dfs1(v, u); 
        if (d1[v] + 1 > d1[u]) {
            d2[u] = d1[u]; c2[u] = c1[u];
            d1[u] = d1[v] + 1; c1[u] = v; 
        }
        else if (d1[v] + 1 > d2[u]) {
            d2[u] = d1[v] + 1;
            c2[u] = v;
        }
    }
    return;
}

int up[N]; 

void dfs2(int u, int fa) {
    for(auto v : G[u]) {
        if (v == fa)
            continue;
        if (c1[u] ^ v)
            up[v] = max(up[u], d1[u]) + 1; 
        else
            up[v] = max(up[u], d2[u]) + 1;
        dfs2(v, u);
    }
    return;
}

void solve() {
    int n; cin >> n;
    rep(i, 1, n) G[i].clear();
    fill(up + 1, up + 1 + n, 0); fill(d1 + 1, d1 + 1 + n, 0); fill(c1 + 1, c1 + n + 1, 0);
    fill(d2 + 1, d2 + 1 + n, 0); fill(c2 + 1, c2 + 1 + n, 0);
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int Ans = INF, Id;
    rep(i, 1, n) if (max(d1[i], up[i]) < Ans)
        Ans = max(d1[i], up[i]), Id = i;
    cout << Ans + 1 << '\n';
    rep(i, 0, Ans) 
        cout << Id << " " << i << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}