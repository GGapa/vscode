//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    auto test = [&]() {
        ll ans = 0;
        rep(i, 1, n) ans += __builtin_popcount(i & m);
        cout << ans << '\n';
    };
    ll ans = 0;
    for(int i = 1, j = 0; i <= n; i *= 2, j++) if(((m >> j) & 1) == 1){
        ll cnt = (n - i + 1) / (i * 2) * i + min((n - i + 1) % (i * 2), i);
        (ans += cnt) %= mod;
    }
    cout << ans << '\n';
    return 0;
}