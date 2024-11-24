#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

const ll INF = 2e18;

void solve() {
    int n;  ll h; cin >> n >> h;
    vector<ll> A(n + 2);
    rep(i ,1, n) cin >> A[i];
    A[n + 1] = INF;
    auto check = [&](ll x) {
        ll res = 0;
        rep(i, 1, n) res += min(x, A[i + 1] - A[i]);
        return res >= h;
    };
    ll l = 1, r = 1e18, ans;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}