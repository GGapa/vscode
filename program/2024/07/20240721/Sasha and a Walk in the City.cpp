#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<VI> G(n + 1), F(n + 1, VI(4));
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    rep(i, 1, n) F[i][1] = 1;
    function<void(int, int)> dfs = [&](int x, int fa) {
        for(auto to : G[x]) if(to != fa) {
            dfs(to, x);
            (F[x][1] *= F[to][1] + 1) %= mod;
            (F[x][2] += F[to][2] + F[to][1]) %= mod;
        }
    };
    dfs(1, 0);  
    cout << F[1][1] + F[1][2] + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}