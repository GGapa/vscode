#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

bool solve() {
    int n, m; cin >> n >> m;
    vector<VI> G(n + 1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    vector<int> vis(n + 1);
    function<int(int)> dfs = [&](int x) {
        int ret = 1;
        vis[x] =1;
        for(auto to : G[x]) if(!vis[to]) ret += dfs(to);
        return ret;
    };
    int A = dfs(1);
    if(A == n) return false;
    int B = dfs(n);
    if(n & 1) return ((1ll * n * (n - 1) / 2) - m) & 1;
    if((A & 1) == (B & 1)) return (((1ll * n * (n - 1) / 2) - m) - A * B) & 1;
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) cout << (solve() ? "First" : "Second") << '\n';
    return 0;
}