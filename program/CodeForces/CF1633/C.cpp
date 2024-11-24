#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    LL hc, dc, hm, dm; cin >> hc >> dc >> hm >> dm;
    LL k, w, a; cin >> k >> w >> a;
    rep(i, 0, k) {
        LL nh = hc + a * i, nd = dc + w * (k - i);
        LL ac = ceil(1.0 * hm / nd), am = ceil(1.0 * nh / dm) ;
        if(ac <= am) return cout << "YES\n", void();
    }
    cout << "NO\n"; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}