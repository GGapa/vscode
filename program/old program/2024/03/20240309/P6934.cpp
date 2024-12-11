// P6934 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, k; cin >> d >> k;
    vector<int> r(d + 1), p(d + 1);
    rep(i, 1, d) cin >> r[i] >> p[i];
    using VL = vector<ll> ;
    vector<VL> F(d + 1, VL(d + 1, 1e18)), D = F;    //F[i][j] 将第 i 到 j 全部替换成某一个值所需要的最小值
    rep(x, 0, 255) rep(i, 1, d) {
        ll s = 0;
        rep(j, i, d) {
            auto &f = F[i][j];
            s += p[j] * (r[j] - x) * (r[j] - x);
            f = min(f, s);
        }
    }
    D[0][0] = 0;    //D[i][j] 区间 [1, i] 之间用 j 段的最优解。
    rep(i, 1, d) rep(j, 1, min(i, k)) rep(ii, 0, i - 1) {
        auto &d = D[i][j];
        d = min(d, D[ii][j - 1] + F[ii + 1][i]);
    }
    cout << D[d][k] << '\n';
    return 0;
}