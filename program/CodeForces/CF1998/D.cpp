#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> F(n + 1, INF);
    vector<VI> G(n + 1);
    for(int i = 1, u, v; i <= m; i++)  
        cin >> u >> v, G[u].emplace_back(v);
    F[0] = 0;
    int t = 0;
    rep(i ,1, n - 1) {
        if(i <= t) cout << 0;
        else cout << 1;
        F[i] = min(F[i], F[i - 1] + 1);
        for(auto to : G[i]) F[to] = min(F[to], F[i] + 1), t = max(t, to - F[to]);
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}