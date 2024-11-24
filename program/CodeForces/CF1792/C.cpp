#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), F(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) F[A[i]] = F[A[i] - 1] + 1;
    int ans = 0;
    per(i, n / 2, 1) ans += (F[n - i + 1] < (n - i + 1) - i + 1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}