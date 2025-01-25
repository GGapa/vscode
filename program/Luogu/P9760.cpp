#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
template<int siz> using AI = array<int, siz>;

constexpr int N = 2e5 + 5;
int n, m; 
int ans[N], A[N];
vector<int> adj[N];
queue<int> q;

int dfn[N], low[N];
void dfs(int u, int pa) {
    dfn[u] = low[u] = ++dfn[N - 1];   
    int tg = dfn[A[u]] ? -1 : -2;
    vector<AI<2>> vec;
    for(auto v : adj[u]) if(v != pa){
        if(dfn[v] == 0) {
            dfs(v, u);
            if(low[v] >= dfn[u]) vec.push_back({dfn[v], dfn[N - 1]});
            if(tg == -2 && dfn[A[u]]) {
                if(low[v] >= dfn[u]) tg = (int)vec.size() - 1;
                else tg = -1;
            }
            low[u] = min(low[u], low[v]);
        }
        else 
            low[u] = min(low[u], dfn[v]);
    }

    if(vec.empty()) return ;
    tg = max(tg, -1);

    for(auto v : adj[u]) {
        int it = prev(lower_bound(vec.begin(), vec.end(), AI<2>{dfn[A[v]], INT_MAX})) - vec.begin();
        if(it != -1 && vec[it][1] < dfn[A[v]]) it = -1;
        if(it != tg && ans[v] == INT_MAX) q.push(v), ans[v] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    fill(ans, ans + 1 + n, INT_MAX);
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);

    rep(i, 1, n) if(A[i] == i) ans[i] = 0, q.emplace(i);
    rep(u, 1, n) {
        for(auto v : adj[u]) if(v == A[u] && ans[u] == INT_MAX) 
            ans[u] = 1, q.emplace(u);
    }

    dfs(1, 0);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) if(ans[u] + 1 < ans[v]){
            q.push(v); ans[v] = ans[u] + 1;
        }
    }

    rep(i, 1, n) cout << (ans[i] >= INT_MAX ? -1 : ans[i]) << " \n"[i == n];

    return 0;
}