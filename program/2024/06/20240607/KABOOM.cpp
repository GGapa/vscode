//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 10301;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    vector<VI> F(n + 1, VI(n + 1));
    rep(i, 1, n) F[i][i] = 1;
    rep(i, 1, n) per(j, i - 1, 1) (F[i][j] = F[i][j + 1] + F[i - j][j]) %= mod;
    ll ans = 0;
    rep(i, a, n - b) (ans += 1ll * (F[i][a] - F[i - 1][a] + mod) * F[n - i][b] % mod) %= mod;
    cout << ans << '\n';
    return 0;
}
