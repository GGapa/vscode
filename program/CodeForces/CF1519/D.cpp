//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> A(n + 1), B(n + 1);
    ll sum = 0;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1,n) cin >> B[i], sum += A[i] * B[i];
    ll ans = 0;
    rep(i, 1, n) {
        ll cnt = 0;
        for(int l = i, r = i; l >= 1 && r <= n; l--, r++) {
            cnt +=  (A[l] - A[r]) * (B[r] - B[l]);
            ans = max(ans, cnt);
        }
    } 
    rep(i, 1, n) {
        ll cnt = 0;
        for(int l = i, r = i + 1; l >= 1 && r <= n; l--, r++) {
            cnt +=  (A[l] - A[r]) * (B[r] - B[l]);
            ans = max(ans, cnt);
        }
    } 
    cout << ans + sum << '\n';
    return 0;
}