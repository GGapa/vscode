#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    LL ans = 0;
    rep(d, 1, 16) {
        vector<LL> B(n + 1);
        LL base = powl(10, d);
        rep(i, 1, n) B[i] = A[i] % base;
        sort(B.begin() + 1, B.end());
        vector<LL> F(21);
        rep(k, 0, 20) {
            for(int i = n, j = 1; i >= 1; i--) {
				while(j <= n && B[i] + B[j] < k * base / 10) j++;
				F[k] += n - j + 1;
			}
        }
        rep(i, 0, 19) ans += (F[i] - F[i + 1]) * (i % 10);
    }
    cout << ans << '\n';
    return 0;
}