// 11:48
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

multiset<int> F[N], mn;
vector<int> G[N];

int get(int x) {return F[x].empty() ? 0 : *F[x].begin() + 1; }
void dfs(int x, int fa) {
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        F[x].insert(get(to));
    }
    if(F[x].size() >= 2) mn.insert(*next(F[x].begin()));
}

void add(int x, int v) {
    if(F[x].size() >= 2) mn.erase(mn.find(*next(F[x].begin())));
    F[x].insert(v);
    if(F[x].size() >= 2) mn.insert(*next(F[x].begin()));
}

void del(int x, int v) {
    if(F[x].size() >= 2) mn.erase(mn.find(*next(F[x].begin())));
    F[x].erase(F[x].find(v));
    if(F[x].size() >= 2) mn.insert(*next(F[x].begin()));
}

int ans = 0;

void dfs2(int x, int fa) {
    ans = max(ans, min(get(x), mn.empty() ? (int)1e9 : *mn.begin()));
    for(auto to : G[x]) if(to != fa) {
        del(x, get(to));
        add(to, get(x));
        dfs2(to, x);
        del(to, get(x));
        add(x, get(to));
    }
}

void solve() {
    int n; cin >> n;
    rep(i, 1, n) F[i].clear(), G[i].clear();
    mn.clear(); ans = 0;
    for(int i = 1, u, v;i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    ans = 0;
    dfs(1, 0);
    dfs2(1, 0);
    cout << ans + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}