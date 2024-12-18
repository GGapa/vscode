#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 1e8;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    vector<ll> S(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    rep(i, 1, n) S[i] = S[i - 1] + A[i];
    ll ans = 0;
    rep(i, 2, n) {
        ll t = upper_bound(A.begin() + 1, A.begin() + i, mod - A[i] - 1) - A.begin() - 1;
        ans += S[i - 1] + (i - 1) * A[i] - (i - t - 1) * mod;
    }
    cout << ans << '\n';
    return 0;
}