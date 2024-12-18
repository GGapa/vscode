#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for (int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> vis(n + 1);
    vector<int> a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i]; rep(i, 1, m) cin >> b[i];
    vector<int> c(1);
    rep(i, 1, m) if (!vis[b[i]])
            c.emplace_back(b[i]), vis[b[i]] = true;
    int x = c.size() - 1;
    for (int i = 1; i <= x; i++) if (a[i] != c[i])
            return cout << "TIDAK\n", void();
    return cout << "YA" << '\n', void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}