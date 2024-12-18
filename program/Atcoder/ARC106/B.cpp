#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e5 + 5;

LL sa = 0, sb = 0;
vector<int> G[N];
int A[N], B[N], vis[N];

void dfs(int x) {
    sa += A[x], sb += B[x]; vis[x] = 1;
    for(auto to : G[x]) if(!vis[to]) dfs(to);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; int m; cin >> m;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    rep(i, 1, n) if(!vis[i]) {
        sa = sb = 0;
        dfs(i);
        if(sa != sb) return cout << "No\n", (0);
    }
    cout << "Yes\n";
    return 0;
}