#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


constexpr int N = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<LL> a(n + 2);
    rep(i, 1, n) cin >> a[i];

    LL A = 0, B = 0, C = 0, ans = 0, D = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (a[i] < B + A) {
            LL K = B + A - a[i];
            if (B < K) A -= K - B, K -= K - B;
            if (A < K) B -= K - A, K -= K - A;
            B -= K, A -= K, D = K, a[i] -= K;
        }
        a[i] -= A + B;

        LL L = min(a[i - 1], a[i]);
        ans += L, a[i - 1] -= L, a[i] -= L, A += L;
        ans += a[i - 1], C += a[i - 1], a[i - 1] = 0;

        a[i] += D, ans -= D, D = 0;
        swap(B, C);
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