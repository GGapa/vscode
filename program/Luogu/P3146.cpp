//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    int ans = 0;
    rep(i, 1, n) cin >> A[i], ans = max(ans, A[i]);
    vector<VI> F(n + 1, VI(n + 1));
    rep(i, 1, n) F[i][i] = A[i];
    rep(j, 1, n) per(i, j - 1, 1) {
        auto &f = F[i][j];
        rep(k, i, j - 1) if(F[i][k] == F[k + 1][j] && F[i][k] != 0) f = max(f, F[i][k] + 1);
        ans = max(ans, f);
    }
    cout << ans << '\n';
    return 0;
}