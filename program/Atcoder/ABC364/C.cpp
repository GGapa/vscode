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
    LL x, y; cin >> x >> y;
    using AI = array<LL, 2>;
    vector<AI> A(n + 1);
    rep(j, 0, 1) rep(i, 1, n) cin >> A[i][j];
    sort(A.begin() + 1, A.end(), [&](const AI& a, const AI &b) {
        return  a[0] > b[0];
    });
    int ans = n;
    LL sx, sy; sx = sy = 0;
    rep(i, 1, n) {
        sx += A[i][0]; sy += A[i][1];

        if(sx > x || sy > y) {
            ans = min(ans, i);
            break;
        }
    }
    sort(A.begin() + 1, A.end(), [&](const AI& a, const AI &b) {
        return  a[1] > b[1];
    });
    sx = sy = 0;
    rep(i, 1, n) {
        sx += A[i][0]; sy += A[i][1];
        if(sx > x || sy > y) {
            ans = min(ans, i);
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}