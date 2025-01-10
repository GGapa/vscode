#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int id, n, m; cin >> id >> n >> m;
    vector<VI> G(n+  1);
    vector<int> F(n+  1), S(n + 1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v);
    
    rep(i, 1, n) {
        F[i] = G[i].size() + 1;
        for(auto to : G[i]) (F[i] += (S[i - 1] - S[to - 1] + mod) % mod) %= mod;
        S[i] = (S[i - 1] + F[i]) % mod;
    }
    cout << S[n] << '\n';
    return 0;
}