#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), S = A;
    vector<VI> F(n + 1, VI(35));
    rep(i ,1, n) {
        cin >>A[i];
        S[i] = S[i - 1] ^ A[i];
        rep(j, 0, 30) F[i][j] = F[i - 1][j] + (S[i] >> j & 1);
    }
    ll ans = 0;
    rep(i, 1, n) {
        int a = A[i];
        int j = __lg(a);
        ans += 1ll * (F[i - 1][j]) * (F[n][j] - F[i - 1][j]);
        ans += 1ll * (i - F[i - 1][j]) * (n - i + 1 - (F[n][j] - F[i - 1][j]));
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