#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    LL ans = 0;
    int g = 0, cnt = n;
    while(1) {
        int mn = A[1];
        rep(i, 1, n) mn = min(mn, __gcd(g, A[i]));
        if(mn == g) break;
        g = mn; ans += g, cnt--;
        // rep(i, 1, n) A[i] = __gcd(A[i], g);
    }
    cout << ans + 1ll * g * cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}