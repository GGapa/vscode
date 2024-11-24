#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int a, b; cin >> a >> b;  
    if(a > b) swap(a, b);
    LL ans = LLONG_MAX;
    rep(m, 1, 1e6) ans = min(ans, 1ll * a / m + (a % m != 0) + b / m + (b % m != 0) + m - 1);
    cout << ans << '\n';
    // int g = __gcd(a, b);
    // int mx = INT_MAX, x = 1, y = 1;
    // for(int i = 2; i * i <= a; i++) if(a % i == 0 && i + a / i < mx) mx = i + a / i, x = i;
    // // cerr << mx << '\n';
    // LL ans = 0; ans = x - 1 + a / x;
    // // cerr << x << " " << ans << '\n';
    // mx = INT_MAX;
    // for(int i = 2; i * i <= b; i++) if(b % i == 0 && i + b / i < mx && (i >= x || b / i >= x)) {
    //     mx = i + b / i;
    //     y = i;
    // }
    // cerr << y << '\n';
    // ans += y - x + b / y;
    // cout << ans << '\n';
 }
/*
机器人的步长最开始越大越好?
并不是这样的，因为有可能越大浪费的越多。
这个最终的步长好像不是很方便确定，那就枚举。
*/


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}