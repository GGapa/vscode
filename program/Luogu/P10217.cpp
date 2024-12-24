#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr LL INF = LLONG_MAX;

LL solve() {
    LL n, k, X, Y; cin >> n >> k >> X >> Y;
    vector<LL> x(n + 1), y(n + 1);
    rep(i, 1, n) cin >> x[i], cin >> y[i], x[i] += x[i - 1], y[i] += y[i - 1];
    if(X == 0 && Y == 0) return 0;

    LL ans = INF, l = 0, r = INF - 1;
    auto work = [&](LL a, LL b) {
        if(a == 0) {if(b < 0) l = INF; }
        else if(a > 0) r = min(r, (LL)floor(1.0 * b / a));
        else l = max(l, (LL)ceil(1.0 * b / a));
    };
    rep(i, 1, n) {
        l = 0, r = INF - 1;
        work(+x[n] + y[n] - k * n, +X + Y - x[i] - y[i] + i * k);
        work(+x[n] - y[n] - k * n, +X - Y - x[i] + y[i] + i * k);
        work(-x[n] + y[n] - k * n, -X + Y + x[i] - y[i] + i * k);
        work(-x[n] - y[n] - k * n, -X - Y + x[i] + y[i] + i * k);
        if(l <= r) ans = min(ans, l * n + i);
    }
    if(ans >= INF) return -1;
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) cout << solve() << '\n';
    return 0;
}
