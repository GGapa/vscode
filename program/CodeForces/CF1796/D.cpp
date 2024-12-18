#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<LL>;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i], A[i] -= x;
    vector<VI> F(n + 1, VI(k + 1, -1e18));
    F[0][0] = 0;
    rep(i, 1, n) rep(j, 0, k) {
        if(F[i - 1][j] >= -1e17)F[i][j] = max({F[i][j], F[i - 1][j] + A[i], A[i]});
        if(j > 0 && F[i - 1][j - 1] >= -1e17) F[i][j] = max({F[i][j], F[i - 1][j - 1] + 2 * x + A[i], 2 * x + A[i]});
    }
    LL ans = 0;
    // rep(i, 1, n) rep(j, 0, k) cerr << F[i][j] << " \n"[j == k];
    rep(i, 1, n) rep(j, max(0ll, k - n + i), k) ans = max(ans, F[i][j]);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
定义 F[i][j] 代表 1 - i 用了 j 次加法得道的最大子段和。
*/