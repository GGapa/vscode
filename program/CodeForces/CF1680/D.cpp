#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    vector<LL> S(n + 1), op(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i], op[i] = op[i - 1] + (A[i] == 0);
    if(abs(S[n]) > op[n] * k) return cout << -1, void();
    LL ans = -1;
    rep(l, 1, n) rep(r, l, n) {
        LL sum = S[r] - S[l - 1], cnt = op[r] - op[l - 1];
        LL ls = S[n] - sum, lc = op[n] - cnt;
        ans = max(ans, min(abs(sum + cnt * k), abs(ls - lc * k)));
        ans = max(ans, min(abs(sum - cnt * k), abs(ls + lc * k)));
    }
    cout << ans + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;   
    while(T--) solve();
    return 0;
}