//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    ll ans = LLONG_MAX;
    ll sa, sb; sa = sb = 0;
    ll fa, fb; fa = fb = 0;
    int ma, mb; ma = mb = INT_MAX;
    rep(i, 1, n) {
        if(i % 2) {
            ma = min(ma, A[i]);
            sa += A[i];
            fa = (n - i / 2) * ma + (sa - ma);
        }
        else {
            mb = min(mb, A[i]);
            sb += A[i];
            fb = (n - (i - 1) / 2) * mb + (sb - mb);
        }
        // cout << fa << " " << fb << '\n';
        if(i >= 2) ans = min(ans, fa + fb);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}