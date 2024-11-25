#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

static constexpr int N = 1e4 + 5;

static int n, m;
static vector<int> G[N];
static vector<int> T[N];

static int A[N], dfn[N], low[N], bel[N], deg[N], dis[N], sum[N], iss[N];
static int cnt, idx; 
vector<int> stk;

// int dfs(int x) {
//     low[x] = dfn[x] = ++idx;
//     stk.push_back(x);
//     for(auto to : G[x]) {
//         if(!dfn[to]) low[x] = min(low[x], dfs(to));
//         else if(!belong[to]) low[x] = min(low[x], dfn[to]);
//     }
//     if(low[x] == dfn[x]) {
//         cnt++;
//         for(int i = -1; i != x; stk.pop_back())
//             belong[i = stk.back()] = cnt;
//     }
//     return low[x];
// }

int dfs(int x) {
    dfn[x] = low[x] = ++idx;
    stk.emplace_back(x);
    iss[x] = 1;
    for(auto to : G[x]) {
        if(!dfn[to]) low[x] = min(low[x], dfs(to));
        else if(iss[to]) low[x] = min(low[x], dfn[to]);
    }
    if(dfn[x] == low[x]) {
        cnt++;
        for(int i = -1; i != x; stk.pop_back()) {
            bel[(i = stk.back())] = cnt; sum[cnt] += A[i], iss[i] = 0;
        }
    }
    return low[x];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v; i <= m; i++) cin >> u >> v, G[u].emplace_back(v);

    rep(i, 1, n) if(!dfn[i]) dfs(i);
    rep(x, 1, n) for(auto to : G[x]) if(bel[to] != bel[x]) 
        T[bel[x]].emplace_back(bel[to]), deg[bel[to]]++;

    queue<int> q;
    rep(i, 1, cnt) {
        if(deg[i] == 0) {
            q.push(i);
        }
        dis[i] = sum[i];
    }

    // cerr << q.size() << '\n';
    while(!q.empty()) {
        int x = q.front(); q.pop();
        cerr << x << '\n';
        for(auto to : T[x]) {
            dis[to] = max(dis[to], dis[x] + sum[to]);
            deg[to]--;
            if(deg[to] == 0) q.push(to);
        }
    }
    // rep(i, 1, n) cerr << dis[i] << " \n"[i == n];
    cout << *max_element(dis, dis + 1 + n) << '\n';
    return 0;
}