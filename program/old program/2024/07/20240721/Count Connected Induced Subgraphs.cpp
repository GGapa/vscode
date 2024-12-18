//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<VI> G(n + 1);
    for(int i = 1, v, u; i < n; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    ll ans = 0;
    function<int(int, int)> dfs = [&](int x, int fa) {
        ll ret = 1;
        for(auto to : G[x]) if(to != fa) (ret *= (dfs(to, x) + 1)) %= mod;
        (ans += ret) %= mod;
        return ret;
    };
    dfs(1, 0);
    cout << ans % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}