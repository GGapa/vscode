#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
#define int long long
void solve() {
    int n, m; cin >> n >> m;
    int cnt = 0, mx = INT_MAX;
    // rep(a, 1, n) rep(b, 1, m) {
    //     if((a + b) % (b * __gcd(a, b)) == 0) {
    //         mx = min(a / b, mx); cnt++;
    //         cout << a << " " << b << '\n';
    //     }
    // }
    // -------------------------

    rep(b, 1, m) for(int a = b; a <= n; a += b)  {
        if(((a + b) / b) % (__gcd(a, b)) == 0 ) {
            // cout << a << " " << b << '\n';
            cnt++;
        }
    }

    // cout << mx << '\n';
    cout << cnt << '\n';
    // int ans = 0;
    // rep(i, 1, n) {
    //     int tp = min((int)sqrt(i), m);
    //     for(int j = 1; j <= tp; j++) {
    //         if(i % j == 0) ans += 1 + (i / j != j && i / j <= m);
    //     }
    // }
    // cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}