#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

struct SCC {
    int n, idx, cnt;
    vector<VI> G;
    VI stk, dfn, low, belong;
    SCC(int _n) : n(_n), G(n + 1), low(n + 1), belong(n + 1), dfn(n + 1) {
        idx = cnt = 0;
    }   
    void add(int u, int v) {G[u].push_back(v); };
    int dfs(int x) {
        low[x] = dfn[x] = ++idx;
        stk.push_back(x);
        for(auto to : G[x]) {
            if(!dfn[to]) 
                low[x] = min(low[x], dfs(to));
            else if(!belong[to])
                low[x] = min(low[x], low[to]);
        }
        if(low[x] == dfn[x]) {
            cnt++;
            for(int i = -1; i != x; stk.pop_back()) 
                i = stk.back(), belong[i] = cnt;
        }
        return low[x];
    }
    void work() {
        rep(i, 1, n) if(!dfn[i]) dfs(i);
    }
    void init(vector<set<int>> &adj, vector<int> &in) {
        rep(i, 1, n) {
            int x = belong[i];
            for(auto to : G[i]) if(belong[to] != x) {
                if(!adj[x].count(belong[to])) in[belong[to]]++;
                adj[x].insert(belong[to]);
            }
        }
    }
};


void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), si(n + 1); vector<LL> S(n + 1);
    rep(i, 1, n) cin >> A[i];
    SCC tj(n); 
    for(int i = 1, u, v; i <= m; i++)
        cin >> u >> v, tj.add(u, v);
    tj.work();
    vector<int> in(n + 1); vector<set<int>> G(n + 1);
    tj.init(G, in);
    queue<int> q;
    rep(i, 1, n) S[tj.belong[i]] += A[i], si[tj.belong[i]]++;
    const LL INF = 1e18;
    vector<pair<int, LL>> F(n + 1, make_pair(0, INF));
    rep(i, 1, tj.cnt) if(!in[i]) q.push(i), F[i] = {si[i], S[i]};
    LL ans = INF, mx = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(mx < F[x].first || (mx == F[x].first && ans > F[x].second)) ans = F[x].second, mx = F[x].first;
        for(auto to : G[x]) {
            in[to]--;
            if(in[to] == 0) q.push(to);
            if(F[to].first < F[x].first + si[to] || (F[to].first == F[x].first + si[to] && F[to].second > F[x].second + S[to])) 
                F[to].first = F[x].first + si[to], F[to].second = F[x].second + S[to];
        }
    }
    cout << mx << " " << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
6 7
1 1 1 1 2 1
1 2
2 3
3 3
3 4
4 1
2 5
3 6
*/