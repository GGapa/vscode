#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int INF = 1e9;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n  + 1), S(n + 1), F(n + 1, -INF);
    F[0] = 0;
    rep(i ,1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    rep(i, 1, n) per(j, n , i) {
        F[i] = max(F[i], S[j] - S[j - i]);
    }
    rep(k, 0, n) {
        int ans = 0;
        rep(i, 1, n) ans = max(ans, F[i] + min(i, k) * x);
        cout << ans << " \n"[k == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}