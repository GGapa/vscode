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
    using AI = array<int, 2>;
    vector<AI> A(n + 1);
    rep(i ,1, n) cin >> A[i][0] >> A[i][1];
    auto calc = [&](int i, int j)  {
        return sqrt((1ll * A[i][0] - A[j][0]) * (A[i][0] - A[j][0]) + 1ll * (A[i][1] - A[j][1]) * (A[i][1] - A[j][1]));
    };
    double ans = 0;
    rep(i, 1, n) ans += calc(i, i - 1);
    ans += calc(n, 0);
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}