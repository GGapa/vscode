#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n; cin >> n;
    LL ans = LLONG_MAX;
    rep(b, 0, 60) {
        LL t = (1ll << b);
        LL a = n / t;
        LL c = n - a * t;
        ans = min(ans, a + b + c);
    }
    cout << ans << '\n';
    return 0;
}