#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1000 + 5;

int vv[N];
vector<int> G[N];
int C[N];
int n, m, cnt = 0;

void dfs1(int x) {
    vv[x] = 1; cnt++;
    for(auto to : G[x]) if(!vv[to]) dfs1(to);
}

bool check(const vector<int> &c, int p, const vector<int> &cc) {
    queue<int> q;
    q.push(1);
    vector<int> vis(n + 1), have(n + 1);
    vector<set<int>> wt(n + 1);
    int num = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(vis[x]) continue;
        num++;
        vis[x] = have[c[x]] = 1;
        for(auto a : wt[c[x]]) if(!vis[a]) q.push(a);
        for(auto to : G[x]) if(!vis[to]) {
            if(have[C[to]] || (p && C[to] == c[to])) q.push(to);
            else wt[C[to]].insert(to);
        }
    }
    rep(i, 1, n) if(vv[i] && !vis[i] && c[i] == cc[i]) num++;
    return num >= cnt;
}

void solve() {
    cin >> n >> m;
    fill(vv, vv + 1 + n, 0); cnt = 0;
    rep(i, 0, n) vector<int>(0).swap(G[i]);
    vector<int> S(n + 1), F(n + 1);
    rep(i, 1, n) cin >> C[i];
    rep(i, 1, n) cin >> S[i];
    rep(i, 1, n) cin >> F[i];
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs1(1);
    if(cnt != n)  rep(i, 1, n) if(!vv[i] && F[i] != S[i]) return cout << "NO\n", void();
    if(check(S, 0, F) && check(F, 1, S)) return cout << "YES\n", void();
    bool tag = true;
    rep(i, 1, n) if(F[i] != S[i]) tag = false;
    if(tag) return cout << "YES\n", void();
    cout << "NO\n";
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
8 7
5 6 4 8 6 2 4 7
6 2 8 1 5 4 8 4
2 6 5 1 8 4 8 4
3 6
7 5
5 6
1 4
6 8
1 2
2 6
*/