#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e4 + 5;

int dfn[N], low[N], bel[N], F[N], sum[N], A[N], deg[N];
int cnt, idx, n, m;
vector<int> G[N], T[N];
vector<int> stk;

int dfs(int x) {
    dfn[x] = low[x] = ++idx;
    stk.emplace_back(x);
    for(auto to : G[x])  {
        if(!dfn[to]) low[x] = min(low[x], dfs(to));
        else if(!bel[to]) low[x] = min(low[x], dfn[to]);
    }
    if(dfn[x] == low[x]) {
        cnt++;
        for(int i = -1; i != x; stk.pop_back()) 
            bel[(i = stk.back())] = cnt;
    }
    return low[x];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v);

    rep(i, 1, n) if(!dfn[i]) dfs(i);

    rep(x, 1, n) {
        sum[bel[x]] += A[x];
        for(auto to : G[x]) if(bel[to] != bel[x]) T[bel[x]].emplace_back(bel[to]), deg[bel[to]]++;
    }
    
    queue<int> q;
    rep(i, 1, cnt) if(!deg[i]) q.emplace(i), F[i] = sum[i];
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto to : T[x]) {
            F[to] = max(F[to], F[x] + sum[to]);
            if(--deg[to] == 0) q.emplace(to);
        }
    }

    cout << *max_element(F, F + 1 + cnt) << '\n';
    return 0;
}