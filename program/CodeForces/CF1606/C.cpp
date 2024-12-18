#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int unsigned long long
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    k = k + 1;
    vector<int> A(n + 1), S = A;
    rep(i ,1, n) cin >> A[i];
    rep(i, 1, n - 1) S[i] = pow(10ll, A[i + 1] - A[i]) - 1;
    S[n] = 1e11;
    ll ans = 0;
    vector<ll> mul(11); mul[0] = 1;
    rep(i, 1, 10) mul[i] = mul[i - 1] * 10;
    rep(i, 1, n) {
        int t = min(k, S[i]);
        ans += mul[A[i]] * t;
        k -= t;
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