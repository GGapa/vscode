#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; int k; cin >> n >> k;
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    if(l1 > l2) swap(l1, l2), swap(r1, r2);
    LL ans = 0, out = LLONG_MAX;
    k -= min(1ll * k, max(0ll, 1ll * (min(r1, r2) - max(l1, l2)) * n));
    if(k <= 0) out = 0;
    for(int i = 1; i <= n && k > 0; i++) {
        int _r = r1;
        if(r1 < l2) _r = l2, ans += l2 - r1;
        int t = min(k, abs(r2 - _r));
        k -= t, ans += t;
        out = min(ans + k * 2, out);

        t = min(k, abs(l1 - l2));
        k -= t, ans += t;
        out = min(ans + k * 2, out);
    } 
    cout << out << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}