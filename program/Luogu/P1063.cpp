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
    vector<int> A(2 * n + 4);
    rep(i ,1, n) cin >> A[i], A[i + n] = A[i];
    int m = n * 2;
    A[2 * n + 1] = A[1];
    vector<VI> F(m + 2, VI(m + 2));
    rep(j, 1, m) per(i, j - 1, max(1, j - n + 1)) {
        auto &f = F[i][j];
        rep(k, i, j - 1) 
            f = max(F[i][k] + F[k + 1][j] + A[i] * A[k + 1] * A[j + 1], f);
    } 
    int ans = 0;
    rep(i, 1, n) ans = max(ans, F[i][i + n - 1]);
    cout << ans << '\n';
    return 0;
}