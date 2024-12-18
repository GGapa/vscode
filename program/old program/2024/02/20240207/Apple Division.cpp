//Apple Division
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n + 1);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 1e18;
    rep(i, 0, 1 << n) {
        ll s1 = 0, s2 = 0;
        rep(j, 0, n - 1) (i & (1 << j) ? s1 : s2) += a[j];
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans << '\n';
    return 0;
}