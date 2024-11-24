#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n, m; cin >> n >> m;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    auto check = [&](LL x) {
        LL ret = 0;
        rep(i, 1, n) ret += min(x, A[i]);
        return ret;
    };
    LL l = 1, r = 1e10, ans = 0;
    while(l <= r) {
        LL mid = l + r >> 1;
        LL t = check(mid);
        if(t <= m) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    if(r > 1e9) return cout << "infinite", 0;
    cout << ans << '\n';
    return 0;
}